Action()
{


		/* 1. Go to HomePage */


	lr_start_transaction("WT_Reservation_homepage_T01");

	lr_think_time(13);

	lr_think_time(9);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("WT_Reservation_homepage_T01",LR_AUTO);

	
	/* 2. Login */

	lr_start_transaction("WT_Reservation_Login_T02");


	lr_think_time(40);

	web_submit_form("login.pl", 
		"Snapshot=t54.inf", 
		ITEMDATA, 
		"Name=username", "Value=alex", ENDITEM, 
		"Name=password", "Value=alex", ENDITEM, 
		"Name=login.x", "Value=64", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("WT_Reservation_Login_T02",LR_AUTO);


	
	/* 3. Go to itinerary */

	lr_think_time(60);

	lr_start_transaction("WT_CancleFlights_itinerary_T03");
	
	
	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t59.inf", 
		LAST);
	
		lr_end_transaction("WT_CancleFlights_itinerary_T03",LR_AUTO);

	
	/* 4. Cancel All */
	
		lr_start_transaction("WT_CanclelFlights_CalncleALL_T04");
		
		lr_think_time(66);
		
		web_submit_form("itinerary.pl", 
			"Snapshot=t60.inf", 
			ITEMDATA, 
			"Name=1", "Value=<OFF>", ENDITEM, 
			"Name=2", "Value=<OFF>", ENDITEM, 
			"Name=3", "Value=<OFF>", ENDITEM, 
			"Name=4", "Value=<OFF>", ENDITEM, 
			"Name=5", "Value=<OFF>", ENDITEM, 
			"Name=6", "Value=<OFF>", ENDITEM, 
			"Name=removeAllFlights.x", "Value=25", ENDITEM, 
			"Name=removeAllFlights.y", "Value=9", ENDITEM, 
			LAST);
	
		lr_end_transaction("WT_CanclelFlights_CalncleALL_T04",LR_AUTO);
	
	
	
	/* 5. SignOff */

	lr_start_transaction("WT_CacnelFlights_SignOff_T05");

	web_reg_find("Text=To make reservations,please enter your account information to the left", 
		LAST);

	lr_think_time(38);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Ordinal=1", 
		"Snapshot=t61.inf", 
		LAST);

	lr_end_transaction("WT_CacnelFlights_SignOff_T05",LR_AUTO);

	return 0;
}