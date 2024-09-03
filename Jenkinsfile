pipeline {
    agent any
    stages {
        stage('Build librhys') {
            agent {
                docker {
                    image 'ghcr.io/rikorose/gcc-cmake:gcc-13'
                }
            }
            steps {
                sh "mkdir -p build && cd build && cmake .. && cmake --build ."

                script {
                    archiveArtifacts artifacts: 'build/'
                }
            }
        }
    }
    
    post {
      success {
        jabberNotify 'admin@xmpp.therhys.co.uk'
      }
    }
}
