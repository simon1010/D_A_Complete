#include <galileo/Framework/IApplicationModel.h>

namespace galileo
{
  const std::string IApplicationModel::getInitialSceneName()
  {
    return m_InitialScene;
  }

  std::map<const std::string, IScene*> IApplicationModel::getScenes() const
  {
    return m_Scenes;
  }

  std::map<const std::string, const boost::any> IApplicationModel::getTransientData() const
  {
    return m_TransientData;
  }

  IScene* IApplicationModel::getInitialScene() const
  {
    return m_Scenes.find(m_InitialScene)->second;
  }

  IApplicationModel::~IApplicationModel()
  {
    ;
  }
}