#include <iostream>

using namespace std;

struct seq_file_loc {

    char name[10];
    int start_location;
    int size;

};

struct ind_file_loc {

    char name[10];
    int locations_array[100];
    int location_array_size;

};

struct lin_file_loc {
    
        char name[10];
        int start_location;
        int end_location;
    
};

int array1[100];
int linked_info_array[100];

seq_file_loc seq[100];
ind_file_loc ind[100];
lin_file_loc lin[100];

void show_array1 () {

    for( int i = 0; i < 100 ; i++ ){

        if ( array1[i] == -1) 
            cout<<"x ";
        else
            cout << array1[i] << " " ;

        if ( (i+1)%10 == 0)
            cout<<endl;
    }
    cout<<endl;
}

void show_linked_info_array () {
    
        for( int i = 0; i < 100 ; i++ ){
    
            if ( linked_info_array[i] == -1) 
                cout<<"x  ";
            else if (linked_info_array[i] < 10)
                cout << linked_info_array[i] << "  " ;
            else
                cout << linked_info_array[i] << " " ;
    
            if ( (i+1)%10 == 0)
                cout<<endl;
        }
        cout<<endl;
    }

void set_array1 () {

    for( int i = 0; i < 100 ; i++ ){

        array1[i] = -1;

    }

}

void set_linked_info_array () {
    
        for( int i = 0; i < 100 ; i++ ){
    
            linked_info_array[i] = -1;
    
        }
    
    }

int check_array_seq(int start, int size){

    for ( int i = start; i < (start+size); i++){

        if (array1[i] != -1)
            return 1;

    }
    return 0;
}

void sequential () {

    set_array1();
    int n_files;
    cout<<"Enter number of files :"<<endl;
    cin >> n_files;

    for ( int i = 0; i < n_files; i++ ){
        cout<<"Enter name of file : ";
        cin>>seq[i].name;
        cout<<"Enter start location : ";
        cin>>seq[i].start_location;
        cout<<"Enter file size (int) : ";
        cin>>seq[i].size;
        cout<<endl;
        
         if (check_array_seq(seq[i].start_location, seq[i].size)) {
             cout<<"ERROR!, file space taken, try again!"<<endl;
             i--;
             continue;
         }

        for( int j = seq[i].start_location; j < (seq[i].start_location+seq[i].size); j++){
            array1[j] = rand() % 2;
        }
    }
    show_array1();
}

void indexed(){

    set_array1();
    int n_files;
    cout<<"Enter number of files :"<<endl;
    cin >> n_files;

    for ( int i = 0; i < n_files; i++ ){
        cout<<"Enter name of file : ";
        cin>>ind[i].name;
        cout<<"Enter file size (int) : ";
        cin>>ind[i].location_array_size;
        cout<<"Enter locations : "<<endl;
        for(int k = 0; k < ind[i].location_array_size; k++ ){
            cin>>ind[i].locations_array[k];
            if(array1[ind[i].locations_array[k] ] != -1) {
                cout<<"location taken!, try again"<<endl;
                k--;
                continue;
            } else {
                array1[ind[i].locations_array[k]] = rand() % 2;
            }
        }
        cout<<endl;

    }
    show_array1();
}

void linked(){
    
        set_array1();
        set_linked_info_array();
        int n_files;
        cout<<"Enter number of files :"<<endl;
        cin >> n_files;
        cout<<endl;
    
        for ( int i = 0; i < n_files; i++ ){
            cout<<"Enter name of file : ";
            cin>>lin[i].name;
            cout<<"Enter start location : ";
            cin>>lin[i].start_location;
            cout<<"Enter end location : ";
            cin>>lin[i].end_location;
            int cur = lin[i].start_location;
            array1[cur] = rand() % 2;
            int x ;
            while (1){
                cout<<cur<<" points to :";
                cin>>x;
                if(linked_info_array[x] != -1){
                    cout<<"location taken!, try again"<<endl;
                    continue;
                } else {
                    array1[x] = rand() % 2;
                    linked_info_array[cur] = x ;
                    cur = x;
                    if(cur == lin[i].end_location){
                        linked_info_array[x] = 0 ;
                        break;
                    }
                }
            }
            cout<<endl;
    
        }
        show_array1();
        show_linked_info_array();
    }

int main (){

    cout<<"1.Sequential"<<endl;
    cout<<"2.Indexed"<<endl;
    cout<<"3.Linked"<<endl;
    int select;
    cin>>select;

    if (select == 1) {
        sequential();   
    } else if (select == 2){
        indexed();
    }else {
        linked();
    }
}