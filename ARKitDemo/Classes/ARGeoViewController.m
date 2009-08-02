//
//  ARGeoViewController.m
//  ARKitDemo
//
//  Created by Zac White on 8/2/09.
//  Copyright 2009 Gravity Mobile. All rights reserved.
//

#import "ARGeoViewController.h"

#import "ARGeoCoordinate.h"

@implementation ARGeoViewController

@synthesize centerLocation;

- (void)startListening {
  [super startListening];
  self.locationManager.desiredAccuracy = kCLLocationAccuracyBest;
  self.locationManager.distanceFilter = 0;
  [self.locationManager startUpdatingLocation];  
}

- (void)setCenterLocation:(CLLocation *)newLocation {
	[centerLocation release];
	centerLocation = [newLocation retain];
	
	for (ARGeoCoordinate *geoLocation in self.locationItems) {
		if ([geoLocation isKindOfClass:[ARGeoCoordinate class]]) {
			[geoLocation calibrateUsingOrigin:centerLocation];
			
			NSLog(@"geo: %@", geoLocation);
		}
	}
}

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation {
  [self setCenterLocation:newLocation];
}

@end
