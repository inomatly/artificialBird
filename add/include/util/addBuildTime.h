#ifndef D_addBuildTime_H
#define D_addBuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  addBuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class addBuildTime
  {
  public:
    explicit addBuildTime();
    virtual ~addBuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    addBuildTime(const addBuildTime&);
    addBuildTime& operator=(const addBuildTime&);

  };

#endif  // D_addBuildTime_H
