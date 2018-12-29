#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <conio.h>
#include <Windows.h>
using namespace std;

class TreeNode;
typedef TreeNode* TreeNodeptr;

class TreeNode
{
	friend class Tree;
private:

	TreeNodeptr* child;
	//TreeNode *parent;
	string data;
	int count_child;

public:

	TreeNode(string name = "")
	{
		//parent = 0;
		data = name;
		count_child  = 0;
	}

};

class Tree
{
private:

	TreeNode *root;

public:

	Tree(){root = 0;}

	void Set_root(string str)
	{
		TreeNode* newchild = new TreeNode(str);
		root = newchild;
	}

	TreeNode* Level_order_search(string name)
	{
		queue<TreeNode*> q;
		TreeNode *current = root;
		while(current)
		{
			if(current->data == name)
				break;
			for(int i = 0; i < current->count_child; i ++)
			{
				if(current->child[i])
					q.push(current->child[i]);
			}
			if(!q.empty()){current = q.front();	q.pop();}
				else		current = 0;
		}
		if(current)
			return current;
		else
			return 0;
	}

	string Parent(TreeNode *temp)
	{
		queue<TreeNode*> q;
		TreeNode *current = root;
		if(temp == root)
			return "";
		while(current)
		{
			for(int i = 0; i < current->count_child; i ++)
			{
				if(current->child[i] == temp)
					//break;
					return current->data;
			}
			for(int i = 0; i < current->count_child; i ++)
			{
				if(current->child[i])
					q.push(current->child[i]);
			}
			if(!q.empty()){current = q.front();	q.pop();}
				else		current = 0;
		}
		/*if(current)
			return current->data;
		else
			return "";*/
	}

	void Set_childs(TreeNode *node, int count)
	{
		string str;
		TreeNode *newchild;
		node->count_child = count;
		int n = node->count_child;
		node->child = new TreeNodeptr[n];
		for(int i = 0; i < n; i ++)
			node->child[i] = new TreeNode;
		for(int i = 0; i < n; i ++)
		{
			cout << "\nEnter child (" << i+1 << ") :";
			cin >> str;
			newchild = new TreeNode(str);
			node->child[i] = newchild;
			//newchild->parent = node;
		}
	}

	void Make_tree_manualy()
	{
		TreeNode *temp;
		int num_child;
		cout << "Enter root name : ";
		string name;	cin >> name;	Set_root(name);
		while(true)
		{
			system("cls");
			cout << "1- Add node" << endl;
			cout << "2- End of making tree" << endl;
			cout << "\nEnter (1/2) : ";
			string state;	cin >> state;
			if(state == "2")
			{
				system("cls");
				cout << endl << "\t\t\tThe tree maked." << endl;
				cout << endl << "(Press any key....)";	getch();
				return;
			}
			if(state == "1")
			{
				cout << "\nEnter name of node for add childs to it : ";	cin >> name;
				temp = Level_order_search(name);
				if(!temp)
					continue;
				else
				{
					cout << "Enter the count of child for (" << name << ") : ";	cin >> num_child;
					Set_childs(temp, num_child);
				}
			}
		}
	}

	void Make_tree_with_file()
	{
		ifstream in("input.txt");
		TreeNode *temp, *newchild;
		int num_child;
		string name;
		in >> name;		Set_root(name);		in.ignore();
		while(!in.eof())
		{
			in >> name >> num_child;
			temp = Level_order_search(name);
			temp->count_child = num_child;
			temp->child = new TreeNodeptr[num_child];
			for(int i = 0; i < num_child; i ++)
				temp->child[i] = new TreeNode;
			for(int i = 0; i < num_child; i ++)
			{
				in >> name;
				newchild = new TreeNode(name);
				temp->child[i] = newchild;
				//newchild->parent = temp;
			}
			in.ignore();
		}
		in.close();
		cout << endl << "\t\t\tThe tree maked." << endl;
		cout << endl << "(press eny key....)";
		getch();
	}

	void Edit()
	{
		TreeNode *temp;
		int num_child;
		string name;
		while(true)
		{
			system("cls");
			cout << "1- Add node" << endl;
			cout << "2- End of edition tree" << endl;
			cout << "\nEnter (1/2) : ";
			string state;	cin >> state;
			if(state == "2")
			{
				cout << endl << "\t\t\tThe edition complected." << endl;
				cout << endl << "(Press eny key....)";
				getch();
				return;
			}
			if(state == "1")
			{
				cout << "\nEnter name of node for add childs to it : ";	cin >> name;
				temp = Level_order_search(name);
				if(!temp)
					continue;
				else
				{
					cout << "\nEnter the count of child for (" << name << ") : ";	cin>>num_child;
					Set_childs(temp, num_child);
				}
			}
		}
	}

	void Save_tree(string file_name)
	{
		ofstream out(file_name);
		TreeNode *temp;
		int num_child;
		string name;
		out << root->data << endl;
		queue<TreeNode*> q;
		TreeNode *current = root;
		while(current)
		{
			name = current->data;
			num_child = current->count_child;
			if(num_child != 0)
				out << name << " " << num_child << " ";
			for(int i = 0; i < num_child; i ++)
			{
				if(current->child[i])
				{
					q.push(current->child[i]);
					name = current->child[i]->data;
				}
				if(i <= num_child - 2)
					out << name << " ";
				if(i == num_child - 1)
					out << name << endl;
			}
			if(!q.empty()){current = q.front();	q.pop();}
			else		current = 0;
		}
		out.close();
		cout << endl << "\t\t\tThe tree saved." << endl;
		cout << endl << "(Press eny key....)";	getch();
		system("cls");
	}

	void Search1()
	{
		string name1, name2;
		TreeNode *node1, *node2;
		do
		{
			system("cls");
			cout << "Enter the name of node(1) : ";	cin >> name1;
			cout << "Enter the name of node(2) : ";	cin >> name2;
			node1 = Level_order_search(name1);
			node2 = Level_order_search(name2);
			if(!node1 || !node2)
			{
				cout << endl;
				if(!node1)
					cout << "The name of node(1) isn't correct." << endl;
				if(!node2)
					cout << "The name of node(2) isn't correct." << endl;
				cout << endl << "Try again . (Press eny key....)";	getch();
			}
		}while(!node1 || !node2);
		string parent1 = "", parent2 ="";
		cout << endl << endl;
		if(node1 != root)		parent1 = Parent(node1);
		if(node2 != root)		parent2 = Parent(node2);
		bool flag1, flag2;
		flag1 = (parent1 == name2 || parent2 == name1);
		if(flag1)
		{
			if(parent1 == name2)
				cout << name2 << " is parent of " << name1 << "."<< endl;
			if(parent2 == name1)
				cout << name1 << " is parent of " << name2 << "."<< endl;
		}
		flag2 = (parent1 == parent2);
		if(flag2)
			cout << "\n\nThe node(1) and node(2) are brother." << endl;
		if(!flag1 && !flag2)
			cout << "\nThere isn't relation between node1 and node2." << endl;
	}

	void Search2()
	{
		string name;
		int state;
		system("cls");
		cout << "Enter the name node : ";	cin >> name;
		TreeNode *node = Level_order_search(name);
		if(node)
		{
			cout << "\n\n";
			cout << "1- Print parent of node" << endl;
			cout << "2- Print childs of node" << endl;
			cout << "3- Print brother of node" << endl;
			cout << "\nEnter (1/2/3) : ";	 cin >> state;
			if(state == 1)
			{
				if(node == root)
					cout << "\n\nThe node is root; Root haven't parent." << endl;
				else
					cout<<"\n\nParent of "<<node->data<<" is "<<Parent(node)<< "."<< endl;
			}
			if(state == 2)
			{
				if((node->count_child) == 0)
					cout << "\n\nThe node haven't child." << endl;
				else if((node->count_child) > 0)
				{
					cout << "\n\nChilds of " << node->data << " :" << endl << endl;
					for(int i = 0; i < node->count_child; i ++)
						cout << node->child[i]->data << "   ";
					cout << endl;
				}
			}
			if(state == 3)
			{
				if(node == root)
					cout << "\n\nThe node is root; Root haven't brother." << endl;
				else
				{
					string str;
					cout << "\n\nBrother of " << node->data << " :" << endl << endl;
					string par = Parent(node);
					TreeNode *paren = Level_order_search(par);
					for(int i = 0; i < paren->count_child; i ++)
					{
						str = paren->child[i]->data;
						if(str != name)
							cout << str << "   ";
					}
				}
			}
		}
	}

	void Application_Pedigree()
	{
		lblEnter:
		cout << "Please, Make tree " << endl << endl << endl;
		cout << "1- Making tree manualy" << endl;
		cout << "2- Making tree with file" << endl;
		cout << "\nEnter (1/2) : ";
		string state;	cin >> state;
		if(state != "1" && state != "2")
		{
			system("cls");
			goto lblEnter;
		}
		system("cls");
		if(state == "1")
			Make_tree_manualy();
		if(state == "2")
			Make_tree_with_file();
		system("cls");
		cout << "\nDo you want to (EDIT) tree(y/n) : ";
		string answer;		cin >> answer;
		system("cls");
		if(answer == "y")
		{
			Edit();	
			system("cls");
		}
		lblsave:
		cout << "\nDo you want to (SAVE) tree(y/n) : ";		cin >> answer;
		system("cls");
		if(answer != "n" && answer != "y")
		{
			system("cls");
			goto lblsave;
		}
		if(answer == "y")
		{
			cout << "\nEnter the name of save file (File name.txt) : ";
			string file_name;	cin >> file_name;
			system("cls");
			Save_tree(file_name);
		}
		while(true)
		{
			system("cls");
			cout << "1- Search 1 [ Relation between two node ]" << endl;
			cout << "2- Search 2 [ (Parent/Childs) of a node ]" << endl;
			cout << "3- Exit" << endl;
			cout << "\nEnter (1/2/3) : ";	cin >> state;
			cout << endl << endl;
			if(state == "1")
				Search1();
			if(state == "2")
				Search2();
			if(state == "3")
				exit(0);
			cout << "\n\n\nPress eny key to continue....";	getch();
		}
	}

};

int main()
{
	Tree t1;
	t1.Application_Pedigree();
	getch();
	return 0;
}