
#include<iostream>
using std::cout;

int getSize(char* a){

    int i = 0;
    while(a[i] != '\0'){
        i++;
    }

    return i;
}

void findDuplicates(char *a){
    int h = 0, size = getSize(a);

    for(int i = 0; i < size; i++){
        int pos = 1;
        pos = pos << (int)a[i] - 97;
        if(h&pos){
            cout << "existing character: " << a[i] << '\n';
        }
        else {
            h = h | pos;
        }
    }
}


int main() {

    char s[] = "finding";
    findDuplicates(s);
    return 0;
}
