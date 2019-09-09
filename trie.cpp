#include<iostream>
#include"headerfile.h"
using namespace std;
typedef struct trie
{
	trie *child[26];
	bool isEnd;
	trie()
	{
		for(int i=0;i<26;i++)
		{
			child[i]=NULL;
		}
		isEnd=false;
	}
}trie;
void insert(trie **root,string key)
{
	trie *curr=*root;
	for(int i=0;i<key.length();i++)
	{
		if(curr->child[key[i]-'a']==NULL)
		curr->child[key[i]-'a']=new trie();
		curr=curr->child[key[i]-'a'];
	}
	curr->isEnd=true;
}
bool search(trie *root,string key)
{
	trie *curr=root;
	for(int i=0;i<key.length();i++)
	{
		if(curr->child[key[i]-'a']==NULL)
		{
			return false;
		}
	curr=curr->child[key[i]-'a'];
	}
return curr->isEnd;
}
int main()
{
	trie *root=new trie();
	struct stat file;
	int c=0;
	DIR *dir;
	struct dirent *dep;
	char * cstr= getenv("PATH");
	char * p = std::strtok (cstr,":");
	if((dir=opendir(p))==NULL)
	cout<<"NOT OPEN";
	while (p!=0)
	{
		if(c==9)
		break;
		while((dep=readdir(dir))!=NULL)
		{
			string k="";
			string h=dep->d_name;
			cout<<h<<" ";
			for(int i=0;i<h.length();i++)
			if((h[i]>='A'&&h[i]<='Z'))
			k+=(h[i]-'A'+'a');
			else if((h[i]>='a'&&h[i]<='z'))
			k+=h[i];
			if(h!="."||h!="..")
			insert(&root,k);
		}
		closedir(dir);	
		p = std::strtok(NULL,":");
		if(p!=0)
		{
			if((dir=opendir(p))==NULL)
			cout<<"NOT OPEN";
		}
		c++;
	}
return 0;
}
	
