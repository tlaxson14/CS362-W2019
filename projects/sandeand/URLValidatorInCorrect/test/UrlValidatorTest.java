

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTesthttp()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("htttp://www.google.com"));
   }

   public void testManualTestwww()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("http://ww.google.com"));
   }
   
   public void testManualTestcom()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("http://www.google.comm"));
   }
   
   public void testManualTestdot()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("http://www.google..com"));
   }
   
   public void testManualTestpup()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("https://www.google.com/search?q=greyhound+puppies&tbm=isch"));
   }
   
   public void testManualTestgov()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("https://www.epa.gov/"));
   }
   
   public void testManualTestfile()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator(new String[] {"http","file"}, UrlValidator.ALLOW_LOCAL_URLS);
      assertTrue(valid.isValid("file:///C:/user/andrew/eclipse/"));
   }
   
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
