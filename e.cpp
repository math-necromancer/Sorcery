#include <iostream>

static const long double G = 6.6743015e-11;
static const long double c = 2.99792458e+8;
static const long double c2 = 8.98755179e+16;

static const long double sun = 1.989e+30;

static const long double reduced_h = 1.054571817e-34;
static const long double pi =  3.141592653589793;
static const long double k_b = 1.38064e-23;

/*No one cares how it works; we care that it works*/
double schwarzschild(const double& M)
{
     double r = (2 * G * M) / c2;
     /*It's in meters, so I'll just return it in Kilometers...*/
     return r / 1e+3;
}

double tempurature(const double& M)
{
     return (2.84143856e-9) / (2.3159338e-32 * M);
}

int main()
{
     double M;
     double rad, tem;
     std::cout << "Yo bro, enter a mass in Solar Masses, and this sick program\nwill calculate the epic stats of a Black Hole based on that!\n";
     std::cin >> M;
     M *= sun;
     rad = schwarzschild(M);
     tem = tempurature(M);
     std::cout << "Yo bro, this sick black hole would have a Radius of " << rad << " km!\nAin't that, like, super crazy?\n\n";
     std::cout << "Also, check out this gnarly temperature it would possess!\n" << tem << " degrees K!\n\n";
     std::cout << "Yo, my esteemed Physics Bro Warrior! Observe the power of the black hole before us!\nDon't touch it, however, because you can't! It's impossble!\n";
}