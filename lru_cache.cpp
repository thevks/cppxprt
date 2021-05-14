#include <iostream>
#include <list>
#include <unordered_map>
#include <assert.h>

using namespace std;

template <class KEY_T, class VAL_T> 
class lru_cache {
private:
    list< pair<KEY_T,VAL_T> > item_list;
    unordered_map<KEY_T, decltype(item_list.begin()) > map;
    size_t cache_size;

public:
    lru_cache(int size) 
    {
        cache_size = size;
    }
    void clean(void);
    void put(const KEY_T &key, const VAL_T &val);
    bool exist(const KEY_T &key);
    VAL_T get(const KEY_T &key);
};

template <class KEY_T, class VAL_T> 
void lru_cache<KEY_T, VAL_T>::clean(void)
{
    while(map.size() > cache_size)
    {
        auto last_it = item_list.end(); 
        last_it--;
        map.erase(last_it->first);
        item_list.pop_back();
    }
}

template <class KEY_T, class VAL_T> 
void lru_cache<KEY_T, VAL_T>::put(const KEY_T &key, const VAL_T &val)
{
    auto it = map.find(key);
    if(it != map.end()){
        item_list.erase(it->second);
        map.erase(it);
    }
    item_list.push_front(make_pair(key,val));
    map.insert(make_pair(key, item_list.begin()));
    clean();
 };

template <class KEY_T, class VAL_T> 
bool lru_cache<KEY_T, VAL_T>::exist(const KEY_T &key)
{
    return (map.count(key)>0);
};

template <class KEY_T, class VAL_T>     
VAL_T lru_cache<KEY_T, VAL_T>::get(const KEY_T &key)
{
    assert(exist(key));
    auto it = map.find(key);
    item_list.splice(item_list.begin(), item_list, it->second);
    return it->second->second;
};

int main(void)
{
    lru_cache<string, int> *cache = new lru_cache<string, int>(4);
     
    cache->put("bar", 2);
    cache->put("grok", 1);
    cache->put("foo", 3);     

    cout<<endl;
    cout << "Value of key bar -> " << cache->get("bar") << endl;
    cout << "Value of key grok -> " << cache->get("grok") << endl;
    cout << "Value of key foo -> " << cache->get("foo") << endl;

    return 0;
}