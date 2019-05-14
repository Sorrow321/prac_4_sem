extern int process(int v3, long long v2, unsigned v1);

int forwardargs(long long v1, int v2, int v3) 
{
    int x = process((int)v1, (long long)v2, (unsigned)v3);
    
    return -x;
}
