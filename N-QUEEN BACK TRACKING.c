class Queen
{
private:
    int Place(int k);
    int *x;
    int num;
public:
    Queen(int n);
    void setQueen();
    void PrintQueen();
    ~Queen();
};
Queen::Queen(int n)
{
    x = new int[n];
    memset(x, -1, n);
    num = n;
}
Queen::~Queen()
{
    delete[] x;
}
void Queen::setQueen()
{
    int k = 0, count = 0;
    while (k >= 0)
    {
        x[k]++;
        while (x[k] < num && Place(k) == 1)
            x[k]++;
        if (x[k] < num && k == num - 1)
        {
            printf(" The first %d A solution :", ++count);
            PrintQueen();
        }
        else if (x[k] < num && k < num - 1)
            k = k + 1;
        else
            x[k--] = -1;
    }
}
int Queen::Place(int k)
{
    for (int i = 0; i < k; i++)
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
            return 1;
    return 0;
}
void Queen::PrintQueen()
{
    for (int i = 0; i < num; i++)
        printf("%d\t", x[i] + 1);
    printf("\n");
}
int main(void)
{
    int n;
    printf(" Please enter the number of queens (n>=4):");
    scanf("%d", &n);
    Queen Q(n);
    Q.setQueen();
    return 0;
}
