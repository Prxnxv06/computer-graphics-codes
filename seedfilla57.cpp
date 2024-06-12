#include<graphics.h>  
#include<iostream>
#include<math.h>
#include<stack>

using namespace std; 
void seedfill(int x,int y)
{
	stack<int> st;
	st.push(x);
	st.push(y);
	while(!st.empty())
	{
		int curry=st.top();
		st.pop();
		int currx=st.top();
		st.pop();
		putpixel(currx,curry,LIGHTGREEN);
		
		if(getpixel(currx,curry+1)!=WHITE && getpixel(currx,curry+1)!=LIGHTGREEN){
			st.push(currx);
			st.push(curry+1);
		}
		if(getpixel(currx+1,curry)!=WHITE && getpixel(currx+1,curry)!=LIGHTGREEN){
			st.push(currx+1);
			st.push(curry);
		}
		if(getpixel(currx,curry-1)!=WHITE && getpixel(currx,curry-1)!=LIGHTGREEN){
			st.push(currx);
			st.push(curry-1);
		}
		if(getpixel(currx-1,curry)!=WHITE && getpixel(currx-1,curry)!=LIGHTGREEN){
			st.push(currx-1);
			st.push(curry);
		}
	}
}

int main()  
{  
	int gd=DETECT,gm;  
    initgraph (&gd,&gm,"c:\\tc\\bgi");     
    setcolor(WHITE);
    
    cout<<"Edge filling algorithm with edgeflag"<<endl;
    
    int maxx = getmaxx();
    int maxy = getmaxy();
    
  rectangle(100,100,300,300);

   seedfill(150,150);
	
    getch();
    return 0;
}  
