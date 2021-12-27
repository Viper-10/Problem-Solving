#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b); 
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a); 
}
int findDistinctCount(const char* a){
    int freq[26] = {0}; 
    int distinctCount = 0;
    
    for(int i = 0;a[i] != '\0'; ++i){
        if(freq[a[i] - 'a'] == 0){
            distinctCount++; 
        }
        freq[a[i] - 'a']++; 
    }        
    
    return distinctCount; 
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinctCountA = findDistinctCount(a), distinctCountB = findDistinctCount(b); 

    if(distinctCountA == distinctCountB) return lexicographic_sort(a, b); 
    
    return distinctCountA - distinctCountB; 
}

int sort_by_length(const char* a, const char* b) {
    int l1 = strlen(a), l2 = strlen(b);  
    
    if(l1 == l2) return lexicographic_sort(a, b); 
    
    return l1 - l2; 
    
}
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
    for(int i = 1;i < len; ++i){
        int storeI = i; 
        for(int j = i-1; j >= 0; --j){
            if(cmp_func(arr[i], arr[j]) < 0){
                char* tempStr = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = tempStr; 
                i--; 
            }
            
            else {
                break;                 
            }
        }
        i = storeI;         
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}