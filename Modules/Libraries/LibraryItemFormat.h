//
//  LibraryItemFormat.h
//  Harvard Mobile
//
//  Created by Alexandra Ellwood on 12/27/10.
//  Copyright 2010 ModoLabs Inc. All rights reserved.
//

#import <CoreData/CoreData.h>


@interface LibraryItemFormat :  NSManagedObject  
{
}

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * code;

@end


