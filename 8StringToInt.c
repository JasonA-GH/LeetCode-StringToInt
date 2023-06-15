int is_digit(char c)
{
    int v = c - 48;
    if(v < 0 || v > 9)
    return -1;
    return v;
}
int size_of_number(char* s, int size)
{
    int c = 0;
    for(int i=0; i < size; i++)
    {
        if(is_digit(s[i]) != -1)
        {
            c++;
        }
        else if(c > 0)
        break;
    }
    return c;
}
int myAtoi(char* s)
{
    int size = strlen(s);
    int started = 0;
    int negative = 1;
    //printf("%s\n", s);
    double answer = 0;
    int numSize = size_of_number(s, size);
    double depth = pow(10, numSize-1);
    for(int i=0; i < size; i++)
    {
        int d = is_digit(s[i]);
        if(d == -1 && s[i] != '-' && s[i] != ' ' && s[i] != '+')
        {
            break;
        }
        else if((s[i] == ' ' || d == -1) && started)
        {
            break;
        }
        else if(s[i] == '-' && !started)
        {
            if(is_digit(s[i+1]) == -1)
            break;
            negative = -1;
        }
        else if(s[i] == '+' && !started)
        {
            if(is_digit(s[i+1]) == -1)
            break;
            negative = 1;
        }
        else if(d != -1)
        {
            answer += d*depth;
            depth/=10;
            if(answer*negative <= INT_MIN)
            {
            answer = INT_MIN;
            break;
            }
            else if(answer*negative > INT_MAX)
            {
            answer = INT_MAX;
            break;
            }
            started = 1;
        }
    }
    answer *= negative;
    
    return answer;
}
