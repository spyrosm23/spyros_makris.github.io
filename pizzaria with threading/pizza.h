#define Torderlow 1
#define Torderhigh 5
#define Norderlow 1
#define Norderhigh 5
#define Pm 35
#define Pp 25
#define Ps 40
#define Tpaymentlow 1
#define Tpaymenthigh 3
#define Pfail 5
#define Cm 10
#define Cp 11
#define Cs 12
#define Tprep 1
#define Tbake 10
#define Tpack 1
#define Tdellow 5
#define Tdelhigh 15

pthread_mutex_t lock;
pthread_cond_t  cond;

pthread_mutex_t lock2;
pthread_cond_t  cond2;

pthread_mutex_t lock3;
pthread_cond_t  cond3;

pthread_mutex_t lock4;
pthread_cond_t  cond4;

pthread_mutex_t lock5;
pthread_cond_t  cond5;

pthread_mutex_t screen;

int sun=0;
int mar=0;
int pep=0;
int spe=0;
int epit=0;
int apot=0;
int Ntel= 2;
int Ncook=2;
int Noven=10;
int Ndeliver=10;
int Neisodos=1;
long megxrono=0;
long sunxronos=0;
long megxronokr=0;
long sunxronoskr=0;

int randnum;
