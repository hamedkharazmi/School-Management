#include<iostream>
#include "list.h"
using namespace std;


template<typename type>
void CList<type>::sort(bool (*cmp)(const type &data1,const type &data2),bool isAscendant)
{
    type temp;
    for(int max=len-1;max!=0;max--)
        for(int i=0;i<max;i++)
            if(isAscendant^(cmp(this->operator[](i),this->operator[](i+1))))
            {
                temp=this->operator[](i);
                this->operator[](i)=this->operator[](i+1);
                this->operator[](i+1)=temp;
            }
}

template<typename type>
void  CList<type>:: push_back(type data)
{
    if(len==0)
    {
        head.LFront=new CLink<type>(nullptr,data);
        len++;
        end=iterator=head.LFront;
        return;
    }
    end->LFront=new CLink<type>(end,data);
    end=end->LFront;
    len++;
}

template<typename type>
void  CList<type>:: push_first(type data)
{
    CLink<type>* temp=head.LFront;
    head.LFront=new CLink<type>(nullptr,data);
    head.LFront->LFront=temp;
    if(len!=0)
        temp->LBack=head.LFront;
    else
        iterator=end=head.LFront;
    len++;
}

template<typename type>
type  CList<type>:: pop(void)
{
    if(len==0)return false;
    type temp=end->data;
    if(len==1)
    {
        delete head.LFront;
        head.LFront=iterator=end=nullptr;
        len--;
        return temp;
    }
    if(iterator==end)iterator=head.LFront;
    end=end->LBack;
    delete end->LFront;
    end->LFront=nullptr;
    len--;
    return temp;
}

template<typename type>
type  CList<type>:: pop_first(void)
{
    if(len==0)return false;
    type temp=head.LFront->data;
    if(len==1)
    {
        delete head.LFront;
        head.LFront=iterator=end=nullptr;
        len--;
        return temp;
    }
    if(iterator==head.LFront)iterator=iterator->LFront;
    head.LFront=head.LFront->LFront;
    delete head.LFront->LBack;
    head.LFront->LBack=nullptr;
    len--;
    return temp;
}

template<typename type>
type  CList<type>:: pop(int index)
{
    if(size()<index)return false;
    type temp=operator[](index);
    erase(index);
    return temp;
}

template<typename type>
void  CList<type>:: insert(int index,type data)
{
    CLink<type> *count,*temp;
    for(count=&head;index&&count->LFront!=nullptr;count=count->LFront,index--);
    temp=new CLink<type>((count->LFront?count->LFront->LBack:nullptr),data,count->LFront);
    count->LFront=temp;
    if(len!=0&&count!=end)temp->LFront->LBack=temp;
    else {
        end=temp;
        if(len==0)iterator=temp;
    }
    len++;
}

template<typename type>
bool  CList<type>:: erase(int index)
{
    if(len==0)return false;
    CLink<type> *count;
    for(count=head.LFront;index&&count;index--,count=count->LFront);
    if(count==nullptr)return false;
    if(count->LBack)count->LBack->LFront=count->LFront;
    else {
        head.LFront=count->LFront;
        if(iterator==count)iterator=count->LFront;
    }
    if(count->LFront)count->LFront->LBack=count->LBack;
    else end=count->LBack;
    count->LFront=nullptr;
    delete count;
    len--;
    return true;
}

template<typename type>
type& CList<type>:: operator[](int index)
{
    CLink<type>* count;
    for(count=head.LFront;index&&count!=nullptr;index--,count=count->LFront);
    return count->data;
}
template<typename type2>
ostream& operator<<(ostream& out,CList<type2>& data)
{
    for(int i=0;i<data.size();i++)out<<data[i]<<endl;
    return out;
}
// end
