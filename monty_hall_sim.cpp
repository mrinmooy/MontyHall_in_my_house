#include<bits/stdc++.h>
using namespace std;

int randi1()
{
    int ret = rand()%3;
    return ret;
}

//int randi2(int x)
//{
//    while(true)
//    {
//        int ax1 = randi1();
//        if(ax1!=x) return ax1;
//    }
//
//}

bool monty_hall_1() // where we keep our choice
{
    vector<int> v(3,0); v[0] = 1;

    int  car_pos  = randi1();

    if(car_pos!=0)
    {
        swap(v[car_pos],v[0]);
    }

    int choice = randi1();

    if(v[choice]==1) return true;
    else return false;

}

bool monty_hall_2() // where we change our choice
{
    vector<int> v(3,0); v[0] = 1;

    int  car_pos  = randi1();

    if(car_pos!=0)
    {
        swap(v[car_pos],v[0]);
    }

    int choice = randi1();

    int x;

    for(int i=0;i<3; i++)   // this is the only part different from the rules of the game
    {
        if(i==choice) continue;
        if(v[i]==0) {x = i; break; }
    }

    int choice2;

    for(int i=0;i<3;i++)
    {
        if(i==choice or i==x) continue;
        else {choice2 = i; break; }
    }

    if(v[choice2]==1) return true; else return false;





}


int main()
{
    srand(time(0));

    int t1 = 10000000, t2 = 100, cnt1 = 0, cnt2 = 0;

    while(t1--)
    {
        if(monty_hall_1()) cnt1++;
        if(monty_hall_2()) cnt2++;
    }

//    while(t2--)
//    {
//
//    }


    cout<<"The cases where we win by keeping our choice = "<<cnt1<<"\n";
    cout<<"The cases where we win by changing our choice = "<<cnt2<<"\n";

    return 0;
}
