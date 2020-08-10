#pragma once
#include <galileo\Framework\global.h>
#include <iostream>

#include <galileo/Framework/IScene.h>
#include <boost/any.hpp>

namespace galileo
{
  class Framework_EXPORT_IMPORT_API IApplicationModel
  {
  public:
    virtual void defineScene() = 0;

    virtual void defineInitialScene() = 0;

    virtual void defineTransientData() = 0;

    virtual const std::string getInitialSceneName();

    std::map<const std::string, IScene*> getScenes() const;

    std::map<const std::string, const boost::any> getTransientData() const;

    IScene* getInitialScene() const;

    virtual ~IApplicationModel();

  protected:
    std::string m_InitialScene;

    std::map<const std::string, IScene*> m_Scenes;
    std::map<const std::string, const boost::any> m_TransientData;
  };
}
