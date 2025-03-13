#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include<cstring>
#define MAX 120
#define card 30

class node{
public:
    std::string colour;
    std::string operation;
    int num;
};
node *stack[MAX];
int top = -1;
int lim=0;
int count=0;
int garbage;
    node* player1[card];
    node* player2[card];
    static int value1;
    static int value2;
    node* discard=new node;
    int totalcards=7;
    
    void clearScreen()
     {
        system("clear");
    }

int add(node* data) {
    if (top < MAX - 1) {  
        stack[++top] = data;
        return 1;
    } else {
        std::cout << "Stack Overflow!\n";
        return 0;
    }
}

void shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(stack, stack + top + 1, g);
}

void Discard()
{
    discard->operation=stack[top]->operation;
    discard->colour=stack[top]->colour;
discard->num=stack[top]->num;
top--;

}

void addplayer1()
{
    for(value1=1;value1<=7;value1++)
    {
       player1[value1]=stack[top];
       top--;
    }
}
void addplayer2()
{
    for( value2=1;value2<=7;value2++)
    {
       player2[value2]=stack[top];
       top--;
    }
}

int drawcard1(node*(&player1)[30],int&value1,int numcards)
{
    for(int i=0;i<numcards;i++)
    {
        player1[value1++]=stack[top];
        top--;
         
    } return 0;
}
void drawcard2(node*(&player2)[30],int&value2,int numcards)
{
    for(int i=0;i<numcards;i++)
    {
        player2[value2++]=stack[top];
        top--;
          
    }
}

void removecard1(node*(&player1)[30],int e)
{
  player1[e]->colour="deleted";
  player1[e]->num=1000;
  player1[e]->operation="deleted";
value1--;
}

void removecard2(node*(&player2)[30],int e)
{
  player2[e]->colour="deleted";
  player2[e]->num=1000;
  player2[e]->operation="deleted";
  value2--;

}
void wildcard2()
{

    std::cout<<1.<<"Blue"<<std::endl;
    std::cout<<2.<<"Red"<<std::endl;
    std::cout<<3.<<"Green"<<std::endl;
    std::cout<<4.<<"Yellow"<<std::endl;
    int input;
    std::cout<<"select the colour you want to change:";
    std::cin>>input;
    if(input==1)
    {
        discard->colour="Blue";
        return ;
    
    }
    if(input==2)
    {
        discard->colour="Red";
        return ;
        
    }
    
    if(input==3)
    {
        discard->colour="Green";
        return ;
        
    }
    if(input==4)
    {
        discard->colour="Yellow";
        return ;
        
    }
    

}
void wildcard1()
{
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int>dist(1,4);
    int input=dist(gen);

    if(input==1)
    {
        discard->colour="Blue";
        return ;
    
    }
    if(input==2)
    {
        discard->colour="Red";
        return ;
        
    }
    
    if(input==3)
    {
        discard->colour="Green";
        return ;
        
    }
    if(input==4)
    {
        discard->colour="Yellow";
        return ;
        
    }
    

}


    void play()
{
    int po;
    int ts;
    while(true)
    {
        clearScreen();
        for(int h=1;h<po;h++)
 {

      if(player1[h]->colour==discard->colour)
      {

        if(player1[h]->operation=="skip_")
        {
            discard->operation=player1[h]->operation;
            discard->colour=player1[h]->colour;
            discard->num=player1[h]->num;
            std::cout<<"the system used a skip"<<std::endl;
            removecard1(player1,h);
            po++;
            continue;
        }
         
        if(player1[h]->operation=="reverse_")
        {
           
            discard->operation=player1[h]->operation;
            discard->colour=player1[h]->colour;
           discard->num=player1[h]->num;
           std::cout<<"the system used a reverse"<<std::endl;
            removecard1(player1,h);
             po++;
             continue;
     
        }

        if(player1[h]->operation=="addtwocard_")
        {
            discard->operation=player1[h]->operation;
            discard->colour=player1[h]->colour;
            discard->num=player1[h]->num;
            std::cout<<"the system used a addtwocard"<<std::endl;
            drawcard2(player2,value2,2);
            removecard1(player1,h);
             po++;
             break;
        }
        discard->operation=player1[h]->operation;
        discard->colour=player1[h]->colour;
       discard->num=player1[h]->num;
       std::cout<<"done"<<std::endl;
         break;
      }
      
      if(player1[h]->num==discard->num)
      {
        discard->operation=player1[h]->operation;
       discard->colour=player1[h]->colour;
      discard->num=player1[h]->num;
      removecard1(player1,h);
      std::cout<<"done"<<std::endl;
        break;

      }
   
      if(player1[h]->operation==discard->operation && player1[h]->num==discard->num)
      {
       
        if(player1[h]->operation=="skip_")
        {
            discard->operation=player1[h]->operation;
            discard->colour=player1[h]->colour;
            discard->num=player1[h]->num;
            std::cout<<"the system used a skip"<<std::endl;
            removecard1(player1,h);
            po++;
            continue;
        }
         
        if(player1[h]->operation=="reverse_")
        {
            discard->operation=player1[h]->operation;
            discard->colour=player1[h]->colour;
           discard->num=player1[h]->num;
           std::cout<<"the system used a reverse"<<std::endl;
            removecard1(player1,h);
             po++;
             continue;
        }

        if(player1[h]->operation=="addtwocard_")
        {
            discard->operation=player1[h]->operation;
            discard->colour=player1[h]->colour;
            discard->num=player1[h]->num;
            std::cout<<"the system used a addtwocard"<<std::endl;
            drawcard2(player2,value2,2);
            removecard1(player1,h);
             po++;
             break;
        }
     
      }

      if(player1[h]->operation=="wildcard_")
      {

        drawcard2(player2,value2,4);
      removecard1(player1,h);
      std::cout<<"the system used a wildcard"<<std::endl;
        break;

      }

      if(player1[h]->operation=="wild")
      {

        removecard1(player1,h);
        wildcard1();
        po++;
        std::cout<<"done"<<std::endl;
         continue ;
      }
else
drawcard1(player1,value1,1);
std::cout<<"didnt had matching card so picked from the deck"<<std::endl;
continue;

 }

 for(int st=0;st<ts;st++)
 {
  
 int i2=0;
 count=0;
 std::cout<<std::endl;
 std::cout<<"The card in discard:";
 std::cout<<"-->"<<discard->operation<<discard->colour<<"-"<<discard->num<<std::endl;
 std::cout<<std::endl;
 std::cout<<"YOUR CARDS"<<std::endl;
 for(int Q=0;Q<30;Q++)
 {
 if(player2[Q]==0)
 {
     continue;
 }
 if(player2[Q]->colour=="deleted" && player2[Q]->operation=="deleted")
 {
    continue;

 }
count++;
      std::cout<<Q<<" "<<player2[Q]->operation<<player2[Q]->colour<<"-"<<player2[Q]->num<<std::endl;
 }
 std::cout<<std::endl;
 std::cout<<"if you want you pick a card from the deck Enter the number 99"<<std::endl;
 std::cout<<std::endl;
 std::cout<<"Enter the card no:";
 std::cin>>i2;
 if(i2<0 || 99<i2>value1)
 {
     std::cout<<"Enter proper card number"<<std::endl;
  st++;
  continue;
 }
 if(i2==99)
 {
     drawcard2(player2,value2,1);
      break;
 }
 
 if( player2[i2]->operation=="wildcard_")
 {
     
         drawcard1(player1,value1,4);
         removecard2(player2,i2);
         ts++;
        continue;
 }
 
 
 
 if(player2[i2]->operation=="wild")
    {
    wildcard2();
    removecard2(player2,i2);
    break;
    }
 
 if (discard->colour == player2[i2]->colour || discard->num == player2[i2]->num || 
     (discard->num == player2[i2]->num && discard->operation == player2[i2]->operation)) 
  {
    if(player2[i2]->operation=="skip_")
    {
     discard->operation=player2[i2]->operation;
     discard->colour=player2[i2]->colour;
     discard->num=player2[i2]->num;
     removecard2(player2,i2);
     ts++;
     continue;
    }
    
    if(player2[i2]->operation=="reverse_")
    {
     discard->operation=player2[i2]->operation;
     discard->colour=player2[i2]->colour;
     discard->num=player2[i2]->num;
     removecard2(player2,i2);
     ts++;
     continue;
    }
 
    if(player2[i2]->operation=="addtwocard_")
    {
     discard->operation=player2[i2]->operation;
     discard->colour=player2[i2]->colour;
     discard->num=player2[i2]->num;
     drawcard1(player1,value1,2);
     removecard2(player2,i2);
   break;
 
    }
     discard->operation=player2[i2]->operation;
     discard->colour=player2[i2]->colour;
     discard->num=player2[i2]->num;
     removecard2(player2,i2);
     break;
  }
 
  else
     {
        //clearScreen();
        std::cout<<"The card not applicable as it doesn't match the colour or number in the discard pile "<<std::endl;
        std::cout<<"if you want you pick a card from the deck Enter the number 99"<<std::endl;
      continue;
      }

 
     }
 
     po++;
     ts++;
  }
     }
    

int main() {
    
    for (int i = 0; i <=15; i++) {
        node* newnode = new node; 
        newnode->colour = "Blue";
        newnode->num = i;
        if(i>9 && i<=11)
        {
            newnode->operation="reverse_";
            newnode->colour="Blue";
            newnode->num=97;
        }
     
        if(i>11 && i<=13)
        {
            newnode->operation="skip_";
            newnode->colour="Blue";
            newnode->num=98;

        }

        if(i>13 && i<=15)
        {
            newnode->operation="addtwocard_";
            newnode->colour="Blue";
            newnode->num=99;
        }
        add(newnode);  
    }
    for (int i = 1; i <=9; i++) {
        node* newnode = new node; 
        newnode->colour = "Blue";
        newnode->num = i;

        add(newnode);  
    }
    for (int i =0; i <=15; i++) {
        node* newnode = new node; 
        newnode->colour = "Red";
        newnode->num = i;
        if(i>9 && i<=11)
        {
            newnode->operation="reverse_";
            newnode->colour="Red";
            newnode->num=97;
        }
     
        if(i>11 && i<=13)
        {
            newnode->operation="skip_";
            newnode->colour="Red";
            newnode->num=98;

        }

        if(i>13 && i<=15)
        {
            newnode->operation="addtwocard_";
            newnode->colour="Red";
            newnode->num=99;
        }

        add(newnode);  
    }
    for (int i =1; i <=9; i++) {
        node* newnode = new node; 
        newnode->colour = "Red";
        newnode->num = i;

        add(newnode);  
    }
    for (int i = 0; i <=15; i++) {
        node* newnode = new node; 
        newnode->colour = "Green";
        newnode->num = i;
        if(i>9 && i<=11)
        {
            newnode->operation="reverse_";
            newnode->colour="Green";
            newnode->num=97;
        }
     
        if(i>11 && i<=13)
        {
            newnode->operation="skip_";
            newnode->colour="Green";
            newnode->num=98;

        }

        if(i>13 && i<=15)
        {
            newnode->operation="addtwocard_";
            newnode->colour="Green";
            newnode->num=99;
        }

        add(newnode);  
    }
    for (int i = 1; i <=9; i++) {
        node* newnode = new node; 
        newnode->colour = "Green";
        newnode->num = i;

        add(newnode);  
    }
    for (int i = 0; i <=15; i++) {
        node* newnode = new node; 
        newnode->colour = "Yellow";
        newnode->num = i;
        if(i>9 && i<=11)
        {
            newnode->operation="reverse_";
            newnode->colour="Yellow";
            newnode->num=97;
        }
     
        if(i>11 && i<=13)
        {
            newnode->operation="skip_";
            newnode->colour="Yellow";
            newnode->num=98;

        }

        if(i>13 && i<=15)
        {
            newnode->operation="addtwocard_";
            newnode->colour="Yellow";
            newnode->num=99;
        }
        add(newnode);  
    }
    for (int i = 1; i <=9; i++) {
        node* newnode = new node; 
        newnode->colour = "Yellow";
        newnode->num = i;

        add(newnode);  
    }
int z=0;



while(z<=8)
{

     if(z>0 && z<=4)
     {
        node* newnode = new node; 
        newnode->operation="wild";
        newnode->colour="card";
        newnode->num=0;
        add(newnode);

     }
     if(z>=5 && z<=8 )
     {
        node* newnode = new node; 
        newnode->operation="wildcard_";
        newnode->colour="add4";
        newnode->num=0;
        add(newnode);
     }
     z++;

}
shuffle();
 Discard();
 addplayer1();
 addplayer2();
 play();

 for (int i = 0; i <= top; i++) {
     delete stack[i]; 
 }

 return 0;
}



