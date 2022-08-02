#include<iostream>
using namespace std; 
class NumberPatterns{
    const int n; 

    void printPatternName(string name){
        cout << name << endl; 
    }

    void leaveSpaces(){
        cout << endl << endl;
    }
public : 
    NumberPatterns(int n):n(n){
        if(n == 0){
            cout << "WHAT IS THE MEANING OF THIS?" << endl;     
        }
    }

    void fullPyramid(){
    /*
            1
           333
          55555
         7777777
        999999999
    */
        printPatternName("Full Pyramid");
        for(int i = 0;i < n; ++i){
            for(int space = 0; space < n-i-1; ++space){
                cout << " "; 
            }
            for(int j = 0;j < 2*i+1; ++j){
                cout << 2*i+1; 
            }
            cout << endl; 
        }

        leaveSpaces();
    }

    void fullPyramidAliter(){
        /*
            1
           321
          54321
         7654321
        987654321 
        */
        printPatternName("Full Pyramid");

       for(int i = 0;i < n; ++i){
           for(int space = 0; space < n-i-1; ++space){
               cout << " ";
           }
           for(int j = 2*i+1; j > 0; --j){
               cout << j; 
           }
           cout << endl;
       }
        leaveSpaces();
    }

    void printDiamond(){
        /*

        1 
       2 2
      3 3 3
     4 4 4 4
    5 5 5 5 5
     4 4 4 4
      3 3 3
       2 2
        1

        */  

       printPatternName("Diamond");

       for(int i = 0;i < n; ++i){
           for(int space = 0; space < n-i-1; ++space){
               cout << " "; 
           }

           for(int j = 0;j < 2*i+1; ++j){
               cout << i+1;
           }

           cout << endl; 
       }

       for(int i = 0;i < n-1; ++i){
           for(int space = 0; space <= i; ++space){
               cout << " "; 
           }

           for(int j = 0;j < 2*(n-i-1)-1;++j){
               cout << n-i-1; 
           }
           cout << endl;
       }
        leaveSpaces();
    }

    void halfDiamond(){
    /* 
        5
        54
        543
        5432
        54321
        543210
        54321
        5432
        543
        54
        5
    */ 
        printPatternName("Half Diamond");
        for(int i = 0;i < n+1; ++i){
            for(int j = 0; j <= i; ++j){
                cout << n-j; 
            }
            cout << endl; 
        }

        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j <= i; ++j){
                cout << n-j; 
            }
            cout << endl; 
        }
        leaveSpaces(); 
    }
    
    void invertedHalfDiamond(){
       /*

        5
       45
      345
     2345
    12345
   012345
    12345
     2345
      345
       45
        5

        */
        printPatternName("Inverted Half Diamond");

        for(int i = 0;i < n+1; ++i){
            for(int space = 0; space < n-i; ++space){
                cout << " "; 
            }

            for(int j = n-i; j <= n; ++j){
                cout << j; 
            }

            cout << endl; 
        }

        for(int i = 0;i < n; ++i){
            for(int space = 0; space <= i; ++space){
                cout << " "; 
            }

            for(int j = i+1; j <= n; ++j){
                cout << j; 
            }
            cout << endl; 
        }

        leaveSpaces(); 
    }

    void fibonacciPyramid(){
        /*
        1 
        1 2
        3 5 8
        13 21 34 55
        89 144 233 377 610
        */

       printPatternName("Fibonacci Pyramid");

       uint64_t t1 = 1, t2 = 2, t3 = 3; 

       if(n >= 1){
           cout << 1 << endl; 
       }

        if(n >= 2){
            cout << 1 << " " << 2 << endl; 
        }
        for(int i = 2; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                cout << t3 << " "; 

                t1 = t2; 
                t2 = t3; 
                t3 = t1+t2; 
            }
            cout << endl; 
        }
        leaveSpaces();
    }

    void butterfly(){
        /*
            1     7
            12   67
            123 567
            1234567
            123 567
            12   67
            1     7
        */

        printPatternName("Butterfly");
        int i = 0, j = n-1; 
        
        // the for loop condition is basically 
        // condition = even ? n/2 : n/2+1; 

        // (n-1)/2 + 1 achieves the same without writing condition. Try for n = 8 and n = 7. You'll understand it. 

        for(int row = 0; row < (n-1)/2+1; ++row){
            for(int col = 0; col < n; ++col){
                if(col <= i || col >= j){
                    cout << col+1; 
                }else cout << " "; 
            }
            cout << endl; 
            i++; 
            j--; 
        }

        
        //I wrote if conditions first, then came up with this short condition that's written below for the second half of the butterfly.
        //It's totally fine if you don't get this. 
        // This is done to ensure that for even numbers and odd numbers we print ((n/2) + 1)th row accordingly. 


        j = (n-1)/2-1; 
        i = n/2+1; 

        for(int row = 0; row < n/2; ++row){
            for(int col = 0; col < n; ++col){
                if(col <= j || col >= i){
                    cout << col+1; 
                }else cout << " "; 
            }
            cout << endl; 
            j--; 
            i++; 
        }

        leaveSpaces();    
    }
};
int main(){
    int n;  
    cin >> n; 

    NumberPatterns p(n); 

    p.fullPyramid(); 
    p.fullPyramidAliter();
    p.printDiamond();
    p.halfDiamond();
    p.invertedHalfDiamond();
    p.fibonacciPyramid();
    p.butterfly(); 

    return 0; 
}