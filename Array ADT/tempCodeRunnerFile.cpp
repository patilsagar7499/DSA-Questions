
     }
     int diff=B[0];
     for(int i=0;i<n;i++)
     {
         if(B[i]-i!=diff)
         {
             cout<<"Missing no:"<<i+diff<<endl;
             break;
         }
     }
}
void unsorted(int n)
{