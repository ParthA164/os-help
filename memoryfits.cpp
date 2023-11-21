#include <iostream>
using namespace std;
void first_fit(int blocksize[], int m, int processsize[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (processsize[i] < blocksize[j])
            {
                flag = 1;
                cout << "Process" << i + 1 << " -> Block" << j + 1;
                cout << endl;
                blocksize[j] = blocksize[j] - processsize[i];
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Process" << i + 1 << " -> Not allocated";
            cout << endl;
        }
    }
}
void worst_fit(int blocksize1[], int m, int processsize1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        int jmax = blocksize1[0];
        int jmaxi = 0;
        for (int j = 1; j < m; j++)
        {
            if (blocksize1[j] > jmax)
            {
                jmax = blocksize1[j];
                jmaxi = j;
            }
        }
        if (processsize1[i] < blocksize1[jmaxi])
        {
            flag = 1;
            cout << "Process " << i + 1 << " -> Block" << jmaxi + 1;
            cout << endl;
            blocksize1[jmaxi] = blocksize1[jmaxi] - processsize1[i];
        }
        if (flag == 0)
        {
            cout << "Process " << i + 1 << " -> Not allocated";
            cout << endl;
        }
    }
}
int find(int j, int blocksize3[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (j == blocksize3[i])
        {

            return i;
        }
    }
}
void Best_fit(int blocksize2[], int m, int processsize2[], int blocksize3[], int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (blocksize2[i] > blocksize2[j])
            {
                swap(blocksize2[i], blocksize2[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (processsize2[i] < blocksize2[j])
            {

                flag = 1;
                cout << "Process" << i + 1 << " -> Block" << find(blocksize2[j], blocksize3, n) + 1;
                cout << endl;
                blocksize2[j] = blocksize2[j] - processsize2[i];
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Process" << i + 1 << " -> Not allocated";
            cout << endl;
        }
    }
}

int main()
{
    int m;
    int n;
    int blocksize[] = {100, 500, 200, 300, 600};
    int processsize[] = {212, 417, 112, 426};
    int blocksize1[] = {100, 500, 200, 300, 600};
    int processsize1[] = {212, 417, 112, 426};
    int blocksize2[] = {100, 500, 200, 300, 600};
    int processsize2[] = {212, 417, 112, 426};
    int blocksize3[] = {100, 500, 200, 300, 600};
    int processsize3[] = {212, 417, 112, 426};
    m = sizeof(blocksize) / sizeof(blocksize[0]);
    n = sizeof(processsize) / sizeof(processsize[0]);
    first_fit(blocksize, m, processsize, n);
    cout << endl;
    worst_fit(blocksize1, m, processsize1, n);
    cout << endl;
    Best_fit(blocksize2, m, processsize2, blocksize3, n);
    cout<<m<<" "<<n;
    cout<<sizeof(blocksize)<<" "<<sizeof(blocksize[0]);
	return 0;
}
