
/* Problem Statement:Refer the standard template library to use list container and using C++/Java implement following member functions of list class :
empty, insert, merge, reverse, sort
*/


/*container.cpp*/

#include<iostream>
#include<cstdlib>
#include<list>
using namespace std;

void display(list <int> &lst)
{
	list<int> :: iterator p;
	for(p=lst.begin();p!=lst.end();++p)
	cout<<*p<<",";
	cout<<"\n\n";
}

int main()
{
	int no,data,op;
	list<int> list1;
	list <int> list2(5);
	list<int>::iterator p;
	list<int>listA,listB;
	cout<<"\n Program to implement STL list container";
	do
	{
	cout<<"\n You R having following options";
	cout<<"\n1:Create list1\n2:Create list2\\n3:Push Front\n4:Push back\n5:Pop front";
	cout<<"\n6:Merge Unsorted\n7:sort\n8:Merge Sorted\n9:Reverse\n10:Exit";
	cout<<"\n Enter Ur option::>";
	cin>>op;
	switch(op)
	{
	case 1:
	cout<<"\n Enter how many elements u want to enter";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		cout<<"Enter Data";
		cin>>data;
		list1.push_back(data);
	}
		cout<<"list1\n";
		display(list1);
	break;
	case 2:
	cout<<"\n Randomly generated";
	cout<<"list2\n";

	for(p=list2.begin();p!=list2.end();++p)
	*p=rand()%100;
	display(list2);
	break;
	//add two elements at the end of list1
	case 3:
		cout<<"Enter Data";
				cin>>data;
	list1.push_front(data);
	display(list1);
	break;
	case 4:
			cout<<"Enter Data";
					cin>>data;
		list1.push_back(data);
		display(list1);
		break;
	case 5:
	cout<<"\n Remove an element at the front of list2";
	list2.pop_front();

	cout<<"Modified list2\n";
	display(list2);
	break;
	case 6:

	listA=list1;
	listB=list2;
	cout<<"\nMerging Two lists";
	listA.merge(listB);
	cout<<"merged unsorted list";
	display(listA);
	break;
	case 7:
		listA=list1;
		listB=list2;
	cout<<"\nSorted lists are::>";
	listA.sort();
	listB.sort();
	cout<<" Sorted list1\n";
			display(listA);
	cout<<"Sorted list2\n";
			display(listB);
	break;
	case 8:
		listA=list1;
		listB=list2;
		listA.sort();
		listB.sort();
		listA.merge(listB);
	cout<<"Merged sorted list\n";
	display(listA);
	break;
	case 9:
	cout<<"\n Reversing a list";
	listA.reverse();
	cout<<"Reversed sorted list\n";
	display(listA);
	break;
	case 10:
		break;
	}
}while(op!=10);
	return 0;
}

/*
output:
-------------------------------------------------------
ubuntu@admin12:~/Desktop/OOMP$ g++ asgn12.cpp
ubuntu@admin12:~/Desktop/OOMP$ ./a.out

 Program to implement STL list container
 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>1

 Enter how many elements u want to enter4
Enter Data10
Enter Data20
Enter Data30
Enter Data40
list1
10,20,30,40,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>2

 Randomly generatedlist2
83,86,77,15,93,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>3
Enter Data5
5,10,20,30,40,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>4
Enter Data50
5,10,20,30,40,50,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>5

 Remove an element at the front of list2Modified list2
86,77,15,93,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>6

Merging Two listsmerged unsorted list5,10,20,30,40,50,86,77,15,93,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>7

Sorted lists are::> Sorted list1
5,10,20,30,40,50,

Sorted list2
15,77,86,93,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>8
Merged sorted list
5,10,15,20,30,40,50,77,86,93,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>9

 Reversing a listReversed sorted list
93,86,77,50,40,30,20,15,10,5,


 You R having following options
1:Create list1
2:Create list2\n3:Push Front
4:Push back
5:Pop front
6:Merge Unsorted
7:sort
8:Merge Sorted
9:Reverse
10:Exit
 Enter Ur option::>10
ubuntu@admin12:~/Desktop/OOMP$
---------------------------------------------------------*/



