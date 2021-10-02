#include <iostream>
using namespace std;

template<typename type>
class CLink
{
private:
    type data;
    CLink<type> *LBack,*LFront;
public:
    CLink(CLink<type> * back=nullptr,type data=0,CLink<type>* front=nullptr){
        LFront=front;
        LBack =back ;
        this->data=data;
    }
    ~CLink()
    {
        if(LFront==nullptr)return ;
        delete LFront;
    }
    template<typename type2>
    friend class CList;
};

template<typename type>
class CList
{
private:
    int len;
    CLink<type> *iterator,head,*end;
public:
    CList():len(0),iterator(nullptr),end(nullptr){}
    CList(const CList& ob)
    {
        iterator=nullptr;
        end=nullptr;
        for(int i=0;i<ob.size();i++)this->push_back()(ob[i]);
    }
    ~CList()
    {
        if(head.LFront!=nullptr)delete head.LFront;
    }
    void clear(void)
    {
        if(head.LFront!=nullptr)delete head.LFront;
        len=0;
    }
    template<typename type2>
    friend ostream& operator<<(ostream& out,CList<type2>& data);
    CList <type> operator+(CList& ob)
    {
        CList temp;
        for(int i=0;i<this->size();i++)temp.push_back()(this->operator[](i));
        for(int i=0;i<ob.size();i++)temp.push_back()(ob.operator[](i));
        return temp;
    }
    void push_back()(type data=0);
    void push_first(type data=0);
    type pop(void);
    type pop(int index);
    type pop_first(void);
    void insert(int index,type data);
    bool erase(int index);
    type& operator[](int index);
    int size(void){return len;}
    bool isEmpty(void)
    {
        if(len==0)return true;
        return false;
    }
    type& iter(void)
    {
        return iterator->data;
    }
    type& iter_next(void)
    {
        if(iterator->LFront==nullptr)
        {
            iterator=head.LFront;
            return iterator->data;
        }
        iterator=iterator->LFront;
        return iterator->data;
    }
    type& iter_back(void)
    {
        if(iterator->LBack==nullptr)
        {
            iterator=end;
            return iterator->data;
        }
        iterator=iterator->LBack;
        return iterator->data;
    }
    type& iter_end(void)
    {
        iterator=end;
        return iterator->data;
    }
    type& iter_first(void)
    {
        iterator=head.LFront;
        return iterator->data;
    }
    void sort(bool (*)(const type &data1,const type &data2),bool isAscendant=true);
};
