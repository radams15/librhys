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
                sh "mkdir -p build && cd build && cmake -D BUILD_SHARED_LIBS=YES .. && cmake --build . && cmake -D BUILD_SHARED_LIBS=NO .. && cmake --build ."

                script {
                    archiveArtifacts artifacts: 'build/librhys.so*, build/librhys.a*, build/rhys_test, build/*.pc, include/'
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
