#ifndef LUNITY_CLIENT_PANEL_WEBPANEL
#define LUNITY_CLIENT_PANEL_WEBPANEL

//#include <httplib.h>
#include <HTTPRequest.hpp>
#include <string>

using namespace std;

class WebPanel {
	static inline WebPanel* instance;
	WebPanel();
	//httplib::Server* svr;
public:
	static WebPanel* getInstance();
	//auto getSvr() -> httplib::Server*;
	auto makeRequest(string url) -> string;
	void start(short port);
	void stop();
};

#endif /* LUNITY_CLIENT_PANEL_WEBPANEL */
