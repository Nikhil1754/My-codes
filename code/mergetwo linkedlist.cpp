#include <bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  node(int x){
    data=x;
    next=NULL;
  }
};
void InsertBeginning(node** head,int x){
  node* temp=new node(x);
  temp->next=*head;
  *head=temp;
}
node* mergelist(node* head1,node* head2){
  node* l1=head1;
  node* l2=head2;
  if(l1==NULL) return l2;
  if(l2==NULL) return l1;
  if(l1->data>l2->data){
    swap(l1,l2);
  }
  node* res=l1;
  while(l1!=NULL && l2!=NULL){
    node* temp=NULL;
    while(l1!=NULL && l1->data<=l2->data){
      temp=l1;
      l1=l1->next;
    }
    temp->next=l2;
    swap(l1,l2);
  }
  return res;
}

void display(node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

int main() 
{
  node* head1=NULL;
  InsertBeginning(&head1,4);
  InsertBeginning(&head1,2);
  InsertBeginning(&head1,1);
  display(head1);
  node* head2=NULL;
  InsertBeginning(&head2,4);
  InsertBeginning(&head2,3);
  InsertBeginning(&head2,1);
  display(head2);
  node* n=NULL;
  n=mergelist(head1,head2);
   display(n);
  
    return 0;
}