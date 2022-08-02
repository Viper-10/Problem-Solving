#include<iostream>
using namespace std; 
class Pyramid{
    const int n; 
    void printPatternName(string name){
        cout << name << endl; 
    }

    void leaveSpaces(){
        cout << endl << endl;
    }
public :
    Pyramid(int n):n(n){
       // this is the constructor that is used to initialize n 
    }

    void rightPyramid(){
        /* 
        
        *
        **
        ***
        ****

        */

        printPatternName("Right Pyramid");
        for(int i = 0;i < n; ++i){
            for(int j = 0;j <= i; ++j){
                cout << "*";
            }
            cout << endl;
        }
        leaveSpaces();
    }

     void leftPyramid(){
         /*    
            *
           **
          ***
         ****
        */
       
        printPatternName("Left Pyramid");

        for(int i = 0;i < n; ++i){
            for(int space = 0; space < n-1-i; ++space){
                cout << " "; 
            }

            for(int j = 0; j <= i; ++j){
                cout << "*"; 
            }

            cout << endl; 
        }

        leaveSpaces(); 
    }

    
    void invertedV(){
        
        /*

            * 
          *   *
        *       * 
      *           *  
      
      */
        
        printPatternName("Inverted V");
        int i = n-1, j = n-1; 

        for(int row = 0; row < n; ++row){
            for(int col = 0; col < 2*n-1; ++col){
                if(col == i || col == j){
                    cout << "*"; 
                }
                else cout << " "; 
            }
            cout << endl; 
            i--; 
            j++; 
        }

        leaveSpaces();
    }

    void printX(){

    /*

      *           * 
        *       * 
          *   * 
            *
          *   * 
        *       *
      *           *   
        
    */ 
        // no of rows and cols is 2*n-1
        printPatternName("X Pattern"); 
        for(int i = 0;i < 2*n-1; ++i){
            for(int j = 0;j < 2*n-1; ++j){
                if(j == i || j == (2*n-1)-i-1){
                    cout << "*"; 
                }
                else cout << " "; 
            }
            cout << endl; 
        }

        leaveSpaces(); 
    }

};
int main(){
    int n = 5; 
    cin >> n; 

    Pyramid p(n);
    p.rightPyramid(); 
    p.leftPyramid(); 
    p.invertedV();
    p.printX(); 
    

}