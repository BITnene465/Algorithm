// 选择使用c++ List, 也可以自建链表，也可以使用c++ 的vector容器或优先队列容器 //
// 大模拟系统，完成操作即可 //
#include<bits/stdc++.h>
using namespace std;
struct commission   // 委托
{
    int stockid;    // 股票id，四位数字,使用%04d 补全
    float price;  // 价格，浮点数
    int quantity;   // 成交量，整数
    char BSflag;    // 买卖标志，b/s
    int orderid;    // 委托id，由程序产生,四位数字
    commission(int id,float p,int q,char BS,int oid):stockid(id),price(p),quantity(q),BSflag(BS),orderid(oid){};
    void info()  // 打印信息
    {
        printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",orderid,stockid,price,quantity,BSflag);
    }
};
list<commission> buyque,sellque;   // 链表实现买/卖队列 , 使用双向链表实现的容器
// map<int,list<commission>::iterator> m;           // 实现 orderid和未完成的委托的映射
int orderid;
int main(void)
{
    int flag;
    while(cin>>flag)
    {
        if(flag==0)break;   //输入0，则结束
        if(flag==1)
        {
            printf("orderid: %04d\n",++orderid);
            int stockid,quantity;
            float price;
            char BSflag;
            cin>>stockid>>price>>quantity>>BSflag;
            if(BSflag=='b'){
                for(auto it=sellque.begin();it!=sellque.end();)
                {
                    if(it->stockid!=stockid){++it;continue;}
                    if(it->price>price)break;
                    float dealprice = (it->price+price)/2.0;
                    if(it->quantity>quantity){
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",dealprice,quantity,orderid,it->orderid);
                        it->quantity -= quantity;
                        quantity = 0;
                        break;
                    }
                    else if(it->quantity==quantity){
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",dealprice,quantity,orderid,it->orderid);
                        quantity = 0;
                        sellque.erase(it++);    // 必须这样，否则出错
                        break;
                    }
                    else{
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",dealprice,it->quantity,orderid,it->orderid);
                        quantity -= it->quantity;
                        sellque.erase(it++);
                    }
                }
                if(quantity){   // 如果还有剩余,插入到队列的对应位置
                    list<commission>::iterator idx = buyque.begin();
                    while(idx!=buyque.end()&&idx->price>=price)idx++;     // 要用大于等于，根据测试用例来的
                    buyque.insert(idx,commission(stockid,price,quantity,BSflag,orderid));
                    // cout<<buyque.size()<<endl;
                }
            }
            else if(BSflag=='s'){
                for(auto it=buyque.begin();it!=buyque.end();)
                {
                    if(it->stockid!=stockid){++it;continue;}
                    if(it->price<price)break;
                    float dealprice = (it->price+price)/2.0;
                    if(it->quantity>quantity){
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",dealprice,quantity,orderid,it->orderid);
                        it->quantity -= quantity;
                        quantity = 0;
                        break;
                    }
                    else if(it->quantity==quantity){
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",dealprice,quantity,orderid,it->orderid);
                        quantity = 0;
                        buyque.erase(it++);
                        break;
                    }
                    else{
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",dealprice,it->quantity,orderid,it->orderid);
                        quantity -= it->quantity;
                        buyque.erase(it++);
                    }
                }
                if(quantity){   // 如果还有剩余,插入到队列的对应位置
                    list<commission>::iterator idx = sellque.begin();
                    while(idx!=sellque.end()&&idx->price<=price)idx++;
                    sellque.insert(idx,commission(stockid,price,quantity,BSflag,orderid));
                    // cout<<sellque.size()<<endl;
                }
            }
        }
        else if(flag==2)   // 通过 stockid 来寻找未成交的委托,懒得用multimap存了，所以就直接搜吧
        {
            int stockid;
            cin>>stockid;
            printf("buy orders:\n");
            for(auto it=buyque.begin();it!=buyque.end();++it)
            {
                if(it->stockid==stockid)it->info();
            }
            printf("sell orders:\n");
            for(auto it=sellque.begin();it!=sellque.end();++it)
            {
                if(it->stockid==stockid)it->info();
            }
        }
        else if(flag==3)   // 通过 orderid 来撤销委托
        {
            int tmp_orderid;
            cin>>tmp_orderid;
            bool Findflag = 0;
            for(auto it=buyque.begin();it!=buyque.end();++it){
                if(it->orderid==tmp_orderid){
                    printf("deleted order:");
                    it->info();
                    Findflag=1;
                    buyque.erase(it);
                    break;
                }
            }
            for(auto it=sellque.begin();it!=sellque.end();++it){
                if(it->orderid==tmp_orderid){
                    printf("deleted order:");
                    it->info();
                    Findflag=1;
                    sellque.erase(it);
                    break;
                }
            }
            if(!Findflag){
                printf("not found\n");
            }
        }
    }
    return 0;
}