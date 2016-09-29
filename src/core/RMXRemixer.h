/*
 Copyright 2016-present Google Inc. All Rights Reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "RMXVariable.h"

@class RMXOverlayWindow;

NS_ASSUME_NONNULL_BEGIN

/**
 The RMXRemixer class is a Singleton class that keeps track of all the Remixes and deals with
 saving/syncing its values.
 */
@interface RMXRemixer : NSObject

/** Starts Remixer. */
+ (void)start;

/** Stops the current Remixer session. */
+ (void)stop;

/** Sends an invitation to the web dashboard. */
+ (void)sendEmailInvite;

/** A unique session id. */
+ (NSString *)sessionId;

/**
 Getter for the UIWindow used by the overlay.
 @return The UIWindow.
 */
+ (RMXOverlayWindow *)overlayWindow;

/**
 Returns a remix with the given key from the dictionary of remixes.
 @param key The key of the remix.
 @return A remix from the dictionary of remixes.
 */
+ (nullable RMXVariable *)variableForKey:(NSString *)key;

/**
 Adds a remix to the dictionary of remixes stored by key.
 @param remix The remix to be added.
 */
+ (void)addVariable:(RMXVariable *)variable;

/**
 Removes a remix from the dictionary of remixes.
 @param remix The remix to be removed.
 */
+ (void)removeVariable:(RMXVariable *)variable;

/**
 Removes a remix with the given key from the dictionary of remixes.
 @param key The dictionary key of the remix.
 */
+ (void)removeVariableWithKey:(NSString *)key;

/**
 Returns all remixes.
 @return An array of all current remixes.
 */
+ (NSArray<RMXVariable *> *)allVariables;

/** Removes all remixes and empties the dictionary of remixes. */
+ (void)removeAllVariables;

/** Saves the remix using one of the storage options. */
+ (void)saveVariable:(RMXVariable *)variable;

/** Update an existing remix using a version from one of our storage sources. */
+ (void)updateVariable:(RMXVariable *)variable usingStoredVariable:(RMXVariable *)storedVariable;

@end

NS_ASSUME_NONNULL_END
