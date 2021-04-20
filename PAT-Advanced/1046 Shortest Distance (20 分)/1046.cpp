#include < iostream > 
using namespace std; 
int main() {
    int n, m; 
    int dist[100001]; 
    int exits[100001]; //记录0到i的距离
int total = 0; 
    scanf("%d",  & n); 
    for (int i = 0; i < n; i++) {
        scanf("%d",  & dist[i]); 
        exits[i] = total; 
        total + = dist[i]; 
    }
    scanf("%d",  & m); 
    while (m--) {
        int start, end; 
        scanf("%d%d",  & start,  & end); 
        if (start == end) {
            printf("0\n"); 
        }else {
            if (start > end) {
                int temp = start; 
                start = end; 
                end = temp; 
            }
            int d = 0; 
            d = exits[end-1] - exits[start-1]; 
            if (total - d < d) {
                d = total - d; 
            }
            printf("%d\n", d); 
        }
    }
    system("pasue"); 
    return 0; 
}