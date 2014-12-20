retrieve <- function(){
  #Grab desktop data as an example
  data <- mysql_query("SELECT event_experimentId AS userid,
                      timestamp AS timestamp
                      FROM ModuleStorage_6978194 WHERE LEFT(timestamp,8) BETWEEN 20140107 AND 20140122
                      AND event_mobileMode IS NULL",
                      "log")
  
  #Convert timestamps, split, and sessionise
  split_by_user <- split(to_seconds(mw_strptime(data$timestamp)), data$userid)
  
  #Sessionise. Use the 3600 second split point
  sessions <- sessionise(split_by_user, 3600)
  #For those of you watching at home I want it noted that split_by_user is an 899k-entry
  #list weighing 142MB in memory. It can be sessionised in FOUR POINT FIVE SECONDS.
  #I knew learning C++ was worth it.
  
  #Return
  return(sessions)
}