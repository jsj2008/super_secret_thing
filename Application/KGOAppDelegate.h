#import <UIKit/UIKit.h>

@class KGOModule;
@class SpringboardViewController;
@class ModoNavigationController;

/*
 * this is a substantially rewritten version of KGOAppDelegate
 * modified primarily for simultaneous iPhone/iPad targeting
 */
@interface KGOAppDelegate : NSObject <UIApplicationDelegate, UIAlertViewDelegate> {
    
    UIWindow *window;
    ModoNavigationController *theNavController;
    SpringboardViewController *theSpringboard;
    UIViewController *appModalHolder;
    
    NSDictionary *_appConfig;
    
    NSArray *_modules; // all registered modules as defined in Config.plist

    NSInteger networkActivityRefCount; // the number of concurrent network connections the user should know about. If > 0, spinny in status bar is shown
    
    NSData *devicePushToken; // deviceToken returned by Apple's push servers when we register. Will be nil if not available.
    NSMutableArray *_unreadNotifications;
    BOOL showingAlertView;
}

- (void)showNetworkActivityIndicator;
- (void)hideNetworkActivityIndicator;

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) ModoNavigationController *theNavController;
@property (nonatomic, retain) SpringboardViewController *springboard;
@property (nonatomic, retain) NSData *deviceToken;

@property (nonatomic, readonly) NSArray *modules;
@property (nonatomic, readonly) NSDictionary *appConfig;

@end


// this was done originally for the tab bar controller
// it may be less relevant for other navigation styles
// but we will find out
@interface KGOAppDelegate (AppModalViewController)

- (void)setupAppModalHolder;
- (void)presentAppModalViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)dismissAppModalViewControllerAnimated:(BOOL)animated;

@end


@interface KGOAppDelegate (Notifications)

- (void)registerForRemoteNotifications:(NSDictionary *)launchOptions;
- (void)updateNotificationUI;
- (void)saveUnreadNotifications;

@property (nonatomic, readonly) NSArray *unreadNotifications;

@end

