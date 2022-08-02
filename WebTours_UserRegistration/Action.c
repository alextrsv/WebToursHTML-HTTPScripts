Action()
{

	

	lr_think_time(9);


	/* 1. Navigate To HomePage */

	lr_start_transaction("WT_Registration_T01");

	
	lr_think_time(14);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t181.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_find("Text=Welcome to the Web Tours site.", 
		LAST);

	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t182.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_think_time(9);

	
	lr_end_transaction("WT_Registration_T01",LR_AUTO);
	

	/* 2. Click on SignUpNow button */

	lr_start_transaction("WT_Registration_SignUp_T02");

	web_reg_find("Text=First time registering?", 
		LAST);

	
	lr_think_time(48);

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t184.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://safebrowsing.googleapis.com/v4/threatListUpdates_fetch?$req="
		"Ch4KDGdvb2dsZWNocm9tZRIOMTAzLjAuNTA2MC4xMzQaKQgFEAEaGwoNCAUQBhgBIgMwMDEwARC8lQ4aAhgLjB47OCIEIAEgAigBGikIARABGhsKDQgBEAYYASIDMDAxMAEQyfUKGgIYCwEYpiwiBCABIAIoARopCAcQARobCg0IBxAGGAEiAzAwMTABEMjNCxoCGAvdgRHSIgQgASACKAEaJwgBEAEaGQoNCAEQBhgBIgMwMDEwAxAUGgIYC8yoxpQiBCABIAIoAxooCAEQCBoaCg0IARAIGAEiAzAwMTAEEJUqGgIYC_DBCzUiBCABIAIoBBooCA8QARoaCg0IDxAGGAEiAzAwMTABEJhyGgIYC0zKuCkiBCABIAIoARonCAoQCBoZCg0IChAIGAEiAzAwMTABEAcaAhgLPmC4tyIEIAEgAigBGicICRABGhkKDQgJEAYYASIDMDAxMAEQIBoCGAtexNHPIgQgASACKAEaKAgIEAEaGg"
		"oNCAgQBhgBIgMwMDEwARCkEBoCGAuv4TM_IgQgASACKAEaKQgNEAEaGwoNCA0QBhgBIgMwMDEwARCjxAEaAhgLuKbd1iIEIAEgAigBGikIAxABGhsKDQgDEAYYASIDMDAxMAEQp9oKGgIYC4sofYYiBCABIAIoARopCA4QARobCg0IDhAGGAEiAzAwMTABEOTFBhoCGAvgVR6JIgQgASACKAEaKAgQEAEaGgoNCBAQBhgBIgMwMDEwARCpExoCGAtTxvskIgQgASACKAEiAggB&$ct=application/x-protobuf&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("WT_Registration_SignUp_T02",LR_AUTO);

	/* 3. Fill user profile */

	lr_start_transaction("WT_Registration_Registr_T03");

	web_reg_find("Text=Thank you", 
		LAST);

	
	lr_think_time(56);

	web_submit_form("login.pl_2", 
		"Snapshot=t185.inf", 
		ITEMDATA, 
		"Name=username", "Value={UserName}", ENDITEM, 
		"Name=password", "Value=olex", ENDITEM, 
		"Name=passwordConfirm", "Value=olex", ENDITEM, 
		"Name=firstName", "Value=Alexander", ENDITEM, 
		"Name=lastName", "Value=Tarasov", ENDITEM, 
		"Name=address1", "Value=dldl", ENDITEM, 
		"Name=address2", "Value=St.Petersburg", ENDITEM, 
		"Name=register.x", "Value=61", ENDITEM, 
		"Name=register.y", "Value=3", ENDITEM, 
		LAST);

	lr_end_transaction("WT_Registration_Registr_T03",LR_AUTO);

	
	/* 4. Click on continue button after signin up */

	lr_start_transaction("WB_Registration_FinishREgistration_T04");


	web_reg_find("Text=to the Web Tours reservation pages", 
		LAST);

	lr_think_time(89);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t186.inf", 
		LAST);

	lr_end_transaction("WB_Registration_FinishREgistration_T04",LR_AUTO);


	/* 5. Click Sing Off */

	lr_start_transaction("WB_Registration_SingOff_T05");


	web_reg_find("Text=To make reservations,please enter your account information to the left.", 
		LAST);

	lr_think_time(55);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t187.inf", 
		LAST);

	lr_end_transaction("WB_Registration_SingOff_T05",LR_AUTO);

	return 0;
}