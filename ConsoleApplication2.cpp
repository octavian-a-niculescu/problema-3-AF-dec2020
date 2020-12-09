#include <iostream>
#include <algorithm>
#include "Header.h"

bool functieComparareIntervalCrescator(Interval interval1, Interval interval2)
{
	return interval1.lo < interval2.lo;
}

void citire(int& n, Interval vectorIntervale[])
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		vectorIntervale[i].citire();
	}
}

void determinareReuniune(int n, Interval vectorIntervale[])
{
	std::sort(vectorIntervale, vectorIntervale + n, functieComparareIntervalCrescator);
	for (int i = 1; i < n; i++)
	{
		if (vectorIntervale[i].lo > vectorIntervale[i - 1].lo && vectorIntervale[i].lo < vectorIntervale[i - 1].hi)
		{
			vectorIntervale[i].lo = vectorIntervale[i - 1].lo;
			if (vectorIntervale[i - 1].hi > vectorIntervale[i].hi)
			{
				vectorIntervale[i].hi = vectorIntervale[i - 1].hi;
			}
		}
		else
		{
			std::cout << vectorIntervale[i-1].lo << " " << vectorIntervale[i-1].hi << std::endl;
		}
	}
	std::cout << vectorIntervale[n-1].lo << " " << vectorIntervale[n-1].hi << std::endl;
}

int main()
{
	int n;
	Interval vectorIntervale[100];
	citire(n, vectorIntervale);
	determinareReuniune(n, vectorIntervale);
}