#ifndef HOTEL_H
#define HOTEL_H
#include"room.h"

struct hotel
{
	char name[20];
	struct room r[6][6];
};

static int hoteltype = 0;
#endif