//#define _CRT_SECURE_NO_WARNINGS
//
////	public
//bool operator>(const Date& dt1, const Date& dt2)
//{
//	return dateComper(dt1, dt2) > 0 ? true : false;
//}
//
//bool operator>=(const Date& dt1, const Date& dt2)
//{
//	return dateComper(dt1, dt2) >= 0 ? true : false;
//}
//
//bool operator<(const Date& dt1, const Date& dt2)
//{
//	return dateComper(dt1, dt2) < 0 ? true : false;
//}
//
//bool operator<=(const Date& dt1, const Date& dt2)
//{
//	return dateComper(dt1, dt2) <= 0 ? true : false;
//}
//
//bool operator==(const Date& dt1, const Date& dt2)
//{
//	return dateComper(dt1, dt2) == 0 ? true : false;
//}
//
//bool operator!=(const Date& dt1, const Date& dt2)
//{
//	return dateComper(dt1, dt2) ? true : false;
//}
//
////	private
//int dateComper(const Date& dt1, const Date& dt2)
//{
//	if ((dt1.year - dt2.year) == 0)
//	{
//		if ((dt1.month - dt2.month) == 0)
//		{
//			return dt1.day - dt2.day;
//		}
//		else
//		{
//			return dt1.month - dt2.month;
//		}
//	}
//	else
//	{
//		return dt1.year - dt2.year;
//	}
//}