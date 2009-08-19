//
//  ARCoordinate.h
//  ARKitDemo
//
//  Created by Zac White on 8/1/09.
//  Copyright 2009 Gravity Mobile. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MapKit/MapKit.h>

@class ARCoordinate;

@protocol ARPersistentItem

@property (nonatomic, readonly) ARCoordinate *arCoordinate;

@optional

// Title and subtitle for use by selection UI.
- (NSString *)title;
- (NSString *)subtitle;

@end


@protocol ARGeoPersistentItem

// Center latitude and longitude of the annotion view.
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

@optional

// Title and subtitle for use by selection UI.
- (NSString *)title;
- (NSString *)subtitle;

@end


@interface ARCoordinate : NSObject {
	double radialDistance;
	double inclination;
	double azimuth;
	
	NSString *title;
	NSString *subtitle;
}

- (NSUInteger)hash;
- (BOOL)isEqual:(id)other;
- (BOOL)isEqualToCoordinate:(ARCoordinate *)otherCoordinate;

+ (ARCoordinate *)coordinateWithRadialDistance:(double)newRadialDistance inclination:(double)newInclination azimuth:(double)newAzimuth;

@property (nonatomic, retain) NSString *title;
@property (nonatomic, copy) NSString *subtitle;

@property (nonatomic) double radialDistance;
@property (nonatomic) double inclination;
@property (nonatomic) double azimuth;

@end
