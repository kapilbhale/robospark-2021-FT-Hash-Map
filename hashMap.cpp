#include <bits/stdc++.h>
using namespace std;

class HashMap   //Hashmap class
{
    int *keyMap;        //array to store keys
    string *valueMap;       //array to store values
    int size;       //current size of hashmap
    int capacity;       //total capacity of hashmap

public:
    HashMap(int capacity)       //Parameterized constructor of Hashmap
    {
        this->capacity=capacity;
        keyMap=new int[capacity];
        valueMap=new string[capacity];
        for(int i=0;i<capacity;i++){       //Initializing hashmap
            keyMap[i]=-1;
            valueMap[i]="";
        }
        size=0;
    }
    void display();                          //function to display all entries in hashmap
    void modFunc(int key,string value);      //Function to find location for key to place in hashmap
    void insert(int key,string value);       //Function to insert key value pair in hashmap
    void getValue(int key);                  //function to get value of a key
    void modify(int key, string value);      //Function to modify key value pair
    void deleteKey(int key);                 //function to delete a key value pair
    void deleteAll();                        //function to clear whole hashmap
    void hashSort(bool isKey);               //function to sort
};

void HashMap ::  display()      //function to display all entries in hashmap
{
    for(int i=0; i<capacity; i++) {
        if(keyMap[i] != -1) {
            cout<<i<<"| "<< keyMap[i] <<" "<< valueMap[i]<<"\n";
        }
        else{
            cout<<i<<"| "<< "NULL "<< "NULL"<<"\n";
        }
    }
}

void HashMap ::  modFunc(int key,string value)      //Function to find location for key to place in hashmap
{
    int index=(key%capacity);
    while(keyMap[index]!=-1){
        if(keyMap[index]==key){
            cout<<"Key already exists"<<endl;
            return;
        }
        index=(index+1)%capacity;
    }
    keyMap[index]=key;
    valueMap[index]=value;
    size++;
    cout<<"Key successfully allocated"<<endl;
}

void HashMap ::  insert(int key,string value)       //Function to insert key value pair in hashmap
{
    if(size==capacity)
        cout<<"HashMap is full"<<endl;
    else
    {
        modFunc(key,value);
    }
}
void HashMap ::  getValue(int key)      //function to get value of a key
{
    int t = key % capacity;
    int i = t;
    do {
        if(keyMap[i] != -1) {
            if(keyMap[i] == key){
                cout<<"Value = "<<valueMap[i]<<endl;
                return;
            }
        }
        i = (i+1)%capacity;
    } while(t != i);
    cout<<"Key not found"<<endl;
}

void HashMap ::  modify(int key, string value) {        //Function to modify key value pair
    int t = key % capacity;
    int i = t;
    do {
        if(keyMap[i] != -1) {
            if(keyMap[i] == key) {
                valueMap[i] = value;
                return ;
            }
        }
        else
            return;
        i = (i+1)%capacity;
    } while(t != i);
    cout<<"Key not found\n";
}

void HashMap ::  deleteKey(int key) {      //function to delete a key value pair
    int t = key % capacity;
    int i = t;
    do {
        if(keyMap[i] != -1) {
            if(keyMap[i] == key) {
                keyMap[i] = -1;
                valueMap[i] = "";
                return ;
            }
        }
        i = (i+1)%capacity;
    } while(t != i);
    cout<<"Key not found\n";
}

void HashMap ::  deleteAll() {      //function to clear whole hashmap
    for(int i=0; i<capacity; i++) {
        keyMap[i] = -1;
        valueMap[i] = "";
    }
    cout<<"Hash map deleted successfully\n";
}                         
    
void HashMap :: hashSort(bool isKey)
{
    int *keyArr = new int[capacity];
    string *valueArr = new string[capacity];
    int n = 0;
    for (int i = 0,j = 0; i<capacity ; i++)
    {
        if (keyMap[i] != -1)
        {
            keyArr[j] = keyMap[i];
            valueArr[j] = valueMap[i];
            j++;
            n++;
        }
    }

    if(isKey)
    {
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                if (keyArr[j] > keyArr[j+1])
                {
                    int tempInt = keyArr[j];
                    keyArr[j] = keyArr[j+1];
                    keyArr[j+1] = tempInt;
                    
                    string tempString = valueArr[j];
                    valueArr[j] = valueArr[j+1];
                    valueArr[j+1] = tempString;

                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                if (valueArr[j].compare(valueArr[j+1]) > 0)
                {
                    int tempInt = keyArr[j];
                    keyArr[j] = keyArr[j+1];
                    keyArr[j+1] = tempInt;
                    
                    string tempString = valueArr[j];
                    valueArr[j] = valueArr[j+1];
                    valueArr[j+1] = tempString;
                }
            }
        }
    }
    cout<<"\n\nSorted Values : \n"<<endl;
    for (int i = 0; i < n ; i++)
    {
        cout<<i<<"| "<< keyArr[i] <<" "<< valueArr[i]<<"\n";
    }
}

int main()
{
    int n;

    cout<<"Enter size of hashmap: ";
    cin>>n;
    HashMap *m=new HashMap(n);

    int choice,c;
    printf("****************************************** HASHMAP WITH LINEAR PROBING ******************************************\n\n");

    do{
        printf("\n\n\t\t**************** MENU *************\n\n");       //Menu
        printf("\t\t|\t1)INSERT\t\t|\n");
        printf("\t\t|\t2)MODIFY\t\t|\n");
        printf("\t\t|\t3)DELETE\t\t|\n");
        printf("\t\t|\t4)DISPLAY\t\t|\n");
        printf("\t\t|\t5)GET VALUE\t\t|\n");
        printf("\t\t|\t6)CLEAR HASHMAP\t\t|\n");
        printf("\t\t|\t7)SORT BY KEYS\t\t|\n");
        printf("\t\t|\t8)SORT BY VALUES\t|\n");
        printf("\t\t|\t9)Exit\t\t\t|\n\n");
        printf("\t\t*********************************\n");
        printf("\n\tEnter Your Choice: ");   // Asking for choice from user to do certain operations
        scanf("%d",&choice);
        int key;
        string value;
        switch(choice)          //switch case
        {
        case 1:
            cout<<"\n\nEnter key value: ";
            cin>>key;
            cin>>value;
            m->insert(key,value);    //call to insert
            break;

        case 2:
            cout<<"\n\nEnter key value: ";
            cin>>key;
            cin>>value;
            m->modify(key,value);        //call to modify
            break;

        case 3:
            cout<<"\n\nEnter key value: ";
            cin>>key;
            m->deleteKey(key);         //Call to delete
            break;

        case 4:
            m->display();        //call to display
            break;

        case 5:
            cout<<"\n\nEnter key: ";
            cin>>key;
            m->getValue(key);        //call to search
            break;

        case 6: m->deleteAll(); break;
        case 7: m->hashSort(true); break;
        case 8: m->hashSort(false); break;
        case 9: exit(0);

        default:                    //Displaying message if wrong option choosed
            printf("\tInvalid Key Entered!!\n\tPlease select correct operation");
        }
    }while(true);     //Continue loop until c==1
}
