  #include <stdio.h>
  #include <stdlib.h>
  struct Node{
      int id;
      float gpa;
      struct Node* prev;
      struct Node* next;
  };
    struct Node* deleteHead ( struct Node * head ) {
      // Assigned head to the next link of the previously allocated head
    struct Node *h;
    h=head->next;
    h->prev=NULL;
    return h;
  }
  struct Node* removeDuplicates ( struct Node * head , int id ) {
      //Deleted all the extra occurrence of an id
    int i=0,m=0;
    struct Node *h =head;
    struct Node *p=NULL;
    struct Node *cur=NULL;
    while(h!=NULL)
      {
        if(h->id==id)
        {
          m++;
          if(m>1)
          {
            (h->prev)->next =h->next;
            if(h->next==NULL)
            {}
            else
            (h->next)->prev=h->prev;
          }
        }
        h=h->next;
      }
    return head;
  }

  struct Node*  reverse ( struct Node * head ) {
      // Code to reverse and dll return new head(4.4)
    struct Node *h=head;
    struct Node *t= NULL;
    while(h->next!=NULL)
      h=h->next;
    t=h;
    struct Node *p=NULL;
    struct Node *cur=NULL;
    int m=0;
    while(h!=NULL)
      {
        cur=h;
        if(m!=0)
        {
          p->next=cur;
        }
        else
        {
          t=cur;
        }
        p=cur;
        h=h->prev;
        m++;
      }
    h=t;
    cur->next=NULL;
    h=t;
    m=0;
    while(h!=NULL)
      {
        cur=h;
        if(m!=0)
        {
          p->next=cur;
          cur->prev=p;
        }
        else
        {
          t=cur;
        }
        p=cur;
        h=h->next;
        m++;
      }
    return t;
  }

  struct Node *rotateByKplaces(struct Node *head, int k){
      // Code to rotate the dll by k places to the right and return new head(4.5)
    struct Node *h=head;
    int m=0;
    struct Node *newhead;
    struct Node *cur=NULL,*p=NULL;
    int n=0;
    while(h!=NULL)
      {
        h=h->next;
        n++;
      }
    int t=0;
    h=head;
    while(h!=NULL)
      {
        if(m>=(n-k))
        {
          cur=h;
          if(m>(n-k)&&t>0)
          {
            p->next=cur;
            cur->prev=p;
          }
          if(t==0)
          {
            newhead=cur;
          }
          p=cur;
          t++;
        }
        m++;
        h=h->next;
      }
    h=head;
    for(int i=0;i<n-k;i++)
      {
        if(i==(n-k-1))
          h->next=NULL;
        cur=h;
        p->next=cur;
        cur->prev=p;
        p=cur;
        h=h->next;
      }
    newhead->prev=NULL;
    return newhead;
  }
    struct Node * createSortedList ( struct Node * head ) {
      // Code to create a new dll sorted by gpa (4.6)
    struct Node *t=NULL;
    struct Node *h=head;
    int n=0;
    while(h!=NULL)
      {
        h=h->next;
        n++;
      }
    h=head;
    for(int i=0;i<n;i++)
      {
        t=h;
        for(int j=i;j<n;j++)
          {
            if(h->gpa<t->gpa)
            {
              float temp=h->gpa;
              h->gpa=t->gpa;
              t->gpa=temp;
              int temp1=h->id;
              h->id=t->id;
              t->id=temp1;
            }
            t=t->next;
          }
        if(i==0)
        {
          head->gpa=h->gpa;
          head->id=h->id;
        }
        h=h->next;
      }
    h=head;
    return h;
  }

  void main() {
      struct Node* head;
      struct Node* sorted_head;
      head = (struct Node*)malloc(sizeof(struct Node));
      sorted_head = (struct Node*)malloc(sizeof(struct Node));
      head->next = NULL;
      head->prev = NULL;
      // code to take n, k, duplicate_id as input
    int n,k,duplicate_id;
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&duplicate_id);
      // code to take input n records input and build a dll(4.1)
    struct Node* cur=NULL,*p1=NULL;
    for(int i=0;i<n;i++)
      {
        cur=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d %f",&cur->id,&cur->gpa);
        if(i==0)
        {
          head=cur;
          head->prev=NULL;
        }
        else
        {
          p1->next=cur;
          cur->prev=p1;
        }
        p1=cur;
      }
      // ...
      // head updated

      head = deleteHead(head);
      head = removeDuplicates(head, duplicate_id);
      head = reverse(head);
      head = rotateByKplaces(head,k);
    struct Node *newhead=NULL,*cur1=NULL,*p=NULL;
    struct Node*h=head;
    int n1=0;
    while(h!=NULL)
    {
      n1++;
      h=h->next;
    }
    h=head;
    for(int i=0;i<n1;i++)
    {
      cur1=(struct Node*)malloc(sizeof(struct Node));
      cur1->id=h->id;
      cur1->gpa=h->gpa;
      if(i==0)
      {
        newhead=cur1;
        newhead->prev=NULL;
      }
      else
      {
        p->next=cur1;
        cur1->prev=p;
      }
      p=cur1;
      h=h->next;
    }
    sorted_head = createSortedList(newhead);
      // Do not modify the code below
      struct Node* curr=head;
      struct Node* tail=head;
      // print head
      while(curr!=NULL){
          printf("%d,%.1f->",curr->id,curr->gpa);
          tail=curr;
          curr=curr->next;
      }
      printf("\n");
      // print head in reverse ordre
      while(tail!=NULL){
          printf("%d,%.1f->",tail->id,tail->gpa);
          tail=tail->prev;
      }
      printf("\n");
      curr=sorted_head;
      tail=curr;
      // print sorted_head in reverse ordre
      while(curr!=NULL){
          printf("%d,%.1f->",curr->id,curr->gpa);
          tail=curr;
          curr=curr->next;
      }
      printf("\n");
      // print sorted_head in reverse ordre
      while(tail!=NULL){
          printf("%d,%.1f->",tail->id,tail->gpa);
          tail=tail->prev;
      }
      printf("\n");
  }
