#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 24, FColor::Blue, true);
#define DRAW_LINE(StartLocation, Endlocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, Endlocation, FColor::Blue,true);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Blue, true);

#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue,true, -1.0f, 0 ,1.f);	\
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Blue, true);		\
	}