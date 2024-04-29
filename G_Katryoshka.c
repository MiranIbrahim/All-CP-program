#include<stdio.h>

int main(){
    
    long long int eye, mouth, body;
    scanf("%lld %lld %lld", &eye, &mouth, &body);

    long long int doll = 0;
    while (body != 0)
    {

        if (eye != 0 && mouth != 0)
        {
            if (mouth <= eye && mouth <= body)
            {
                doll += mouth;
                body -= mouth;
                eye -= mouth;
                mouth = 0;
            }
            else
            {
                doll += eye;
                body -= eye;
                mouth -= eye;
                eye = 0;
            }
        }
        else
        {
            long long int _doll = eye / 2;

            if (_doll >= body)
            {
                doll += body;
            }
            else
            {
                doll += _doll;
            }
            break;
        }
    }
    printf("%lld\n", doll);
    return 0;
}