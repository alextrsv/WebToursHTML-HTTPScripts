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
		"Name=username", "Value={UserName}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=64", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("WT_Reservation_Login_T02",LR_AUTO);

	/* 3. Go to Flights */

	lr_think_time(27);

	lr_start_transaction("WT_Reservation_Flights");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t55.inf", 
		LAST);

	lr_end_transaction("WT_Reservation_Flights",LR_AUTO);

	/* 4. Find Flight */

	lr_start_transaction("WT_Reservation_FindFlight_T04");

	lr_think_time(57);

	web_submit_form("reservations.pl", 
		"Snapshot=t56.inf", 
		ITEMDATA, 
		"Name=depart", "Value={Depart}", ENDITEM, 
		"Name=departDate", "Value=08/03/2022", ENDITEM, 
		"Name=arrive", "Value={Arrive}", ENDITEM, 
		"Name=returnDate", "Value=08/04/2022", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=58", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("WT_Reservation_FindFlight_T04",LR_AUTO);


	/* 5. Choose Flight */

	lr_think_time(29);

	lr_start_transaction("WT_Reservation_ChooseFlight_T05");

	web_submit_form("reservations.pl_2", 
		"Snapshot=t57.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=201;301;08/03/2022", ENDITEM, 
		"Name=reserveFlights.x", "Value=35", ENDITEM, 
		"Name=reserveFlights.y", "Value=15", ENDITEM, 
		LAST);

	lr_end_transaction("WT_Reservation_ChooseFlight_T05",LR_AUTO);


	/* 6. Payment Details */

	lr_start_transaction("WT_Reservation_fill payment_T06");

	lr_think_time(53);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t58.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Alexander", ENDITEM, 
		"Name=lastName", "Value=Tarasov", ENDITEM, 
		"Name=address1", "Value=Ramenskya", ENDITEM, 
		"Name=address2", "Value=St.Petersburg", ENDITEM, 
		"Name=pass1", "Value=Alexander Tarasov", ENDITEM, 
		"Name=creditCard", "Value=7676767676", ENDITEM, 
		"Name=expDate", "Value=66", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=37", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("WT_Reservation_fill payment_T06",LR_AUTO);

	/* 7. SignOff */

	lr_think_time(39);

	lr_start_transaction("WT_Reservation_SignOff_T07");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t59.inf", 
		LAST);

	lr_end_transaction("WT_Reservation_SignOff_T07",LR_AUTO);

	return 0;
}