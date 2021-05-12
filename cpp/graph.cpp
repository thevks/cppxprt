#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class node 
{
	public:
		int job;
		bool visited;
		vector<node *>	pre_reqs;
		node(int job);		
};

node::node(int job)
{
	this->job = job;
	visited = {};
	pre_reqs = {};
}

class job_graph
{
	public:
		job_graph(vector<int> jobs);
		unordered_map<int, node *> graph;
		vector<node *> nodes;
		void add_node(int job);
		void add_pre_req(int job, int pre_req);
		node * get_node(int job);
};

job_graph::job_graph(vector<int> jobs)
{
	nodes = {};
	for (int job: jobs)
		add_node(job);

}

void job_graph::add_node(int job)
{
	node *n = new node(job);

	graph[job] = n;
	nodes.push_back(n);
}

void job_graph::add_pre_req(int job, int pre_req)
{
	node *job_node = get_node(job);
	node *pre_req_node = get_node(pre_req);
	
	job_node->pre_reqs.push_back(pre_req_node);
}

node *job_graph::get_node(int job)
{
	return graph[job];	
}

void print_nodes_with_pre_reqs(job_graph *graph)
{
	for (node *n : graph->nodes) 
	{
		cout << "node : " << n->job << " --> ";

		for (node *p : n->pre_reqs)
			cout<<p->job << " ";
	
		cout<<endl;
	}
}

int main(void)
{
	vector<int> jobs{1,2,3,4,5};
	job_graph *graph = new job_graph(jobs);

	graph->add_pre_req(2, 1);
	graph->add_pre_req(2, 3);

	graph->add_pre_req(4, 1);
	graph->add_pre_req(4, 3);

	graph->add_pre_req(5, 1);
	graph->add_pre_req(5, 2);

	print_nodes_with_pre_reqs(graph);

	return 0;
}