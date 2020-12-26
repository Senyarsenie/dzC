#include <iostream>

using namespace std;

void bubblesort(int a[]){
   for(int i=0;i<5;i++){
    for(int j=0;j<4;j++){
        if(a[i]>a[j]){
            swap(a[i],a[j]);
        }
    }
   }
}

void bubblesort(double a[]){
   for(int i=0;i<5;i++){
    for(int j=0;j<4;j++){
        if(a[i]>a[j]){
            swap(a[i],a[j]);
        }
    }
   }
}


int main()
{
    setlocale(LC_ALL,"rus");
    int choice;
    cout<<"¬ведите ваш выбор:"<<endl<<"1 - int"<<endl<<"2-double"<<endl;
    cin>>choice;
    if(choice == 1){
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    bubblesort(a);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    }
    if(choice == 2){
    double a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    bubblesort(a);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    }


    return 0;
}
