// Std. Includes
#include <string>

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GL includes
#include "Shader.h"
#include "Camera.h"
#include "Model.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other Libs
#include "SOIL2/SOIL2.h"

// Properties
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Function prototypes
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void MouseCallback(GLFWwindow* window, double xPos, double yPos);
void DoMovement();

// Camera
Camera camera(glm::vec3(-1.5f, 2.0f, 25.0f));
bool keys[1024];
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

float rot0 = 0.0f;
float rot1 = 0.0f;
float rot2 = 0.0f;
float rot3 = 0.0f;
float rot4 = 0.0f;
float rot5 = 0.0f;
float rot6 = 0.0f;
float rot7 = 0.0f;
float rot8 = 0.0f;
float rot9 = 0.0f;
float rot10 = 0.0f;
float rot11 = 0.0f;
float rot12 = 0.0f;
float rot13 = 0.0f;
float rot14 = 0.0f;
float rot15 = 0.0f;
float rot16 = 0.0f;
float mov = 0.0f;
float mov1 = 0.0f;
float mov2 = 0.0f;
bool on = false;
bool off = false;
bool on1 = false;
bool off1 = false;
bool on2 = false;
bool off2 = false;
bool on3 = false;
bool off3 = false;
bool bote = false;
bool gabinetesizq = false;
bool gabinetesder = false;
bool puertaF = false;
bool puertaC = false;
bool chapa = false;
bool puerta = false;
bool puertita = false;
bool silla = false;
bool girar = false;
bool caer = false;
bool mover = false;
bool mover1 = false;
bool perilla1 = false;
bool perilla2 = false;
bool perilla3 = false;
bool perilla4 = false;
bool drop = false;
bool rodar1 = false;
bool rodar2 = false;

int main()
{
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Proyecto Final - Cocina de Garfield", nullptr, nullptr);

    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

    // Set the required callback functions
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, MouseCallback);

    // GLFW Options
    //glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_DISABLED );

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // Define the viewport dimensions
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // OpenGL options
    glEnable(GL_DEPTH_TEST);

    // Setup and compile our shaders
    Shader shader("Shaders/modelLoading.vs", "Shaders/modelLoading.frag");

    // Load models FACHADA
    Model Fachada((char*)"Models/Fachada/Fachada/fachada.obj");
    Model PuertaCasa((char*)"Models/Fachada/Puerta/PuertaFachada.obj");
    // Load models Sala
    Model ParedesSala((char*)"Models/Cocina/ParedesCocina/paredessala.obj");
    Model VentanaSala((char*)"Models/Sala/Ventanas/ventanas.obj");
    Model Chimenea((char*)"Models/Sala/Chimenea/chimenea.obj");
    Model Lampara((char*)"Models/l.obj");
    Model Puertita((char*)"Models/Puerta/puerta.obj");

    // Load models CUARTO
    Model ParedesCocina((char*)"Models/Cocina/ParedesCocina/paredescocina.obj");
    Model Estufa((char*)"Models/Cocina/Estufa/estufa.obj");
    Model Ventana((char*)"Models/Cocina/Ventana/ventana.obj");
    Model Refrigerador((char*)"Models/Cocina/Refrigerador/refrigerador.obj");
    Model Mesa((char*)"Models/Cocina/Mesa/mesa.obj");
    Model Silla1((char*)"Models/Cocina/Silla1/silla1.obj");
    Model Silla2((char*)"Models/Cocina/Silla2/silla2.obj");
    Model Bote((char*)"Models/Cocina/Bote/bote.obj");
    Model TapaBote((char*)"Models/Cocina/TapaBote/tapabote.obj");
    Model PedalBote((char*)"Models/Cocina/PedalBote/pedalbote.obj");
    Model Fregadero((char*)"Models/Cocina/Fregadero/fregadero.obj");
    Model Gabinete((char*)"Models/Cocina/Gabinete/gabinete.obj");
    Model Cajonera((char*)"Models/Cocina/Cajonera/cajonera.obj");
    Model PuertaCocina((char*)"Models/Cocina/Puerta/puertacocina.obj");
    Model Gabinete1((char*)"Models/Cocina/Gabinete1/gabinete1.obj");
    Model Gabinete2((char*)"Models/Cocina/Gabinete2/gabinete2.obj");
    Model Gabinete3((char*)"Models/Cocina/Gabinete3/gabinete3.obj");
    Model Gabinete4((char*)"Models/Cocina/Gabinete4/gabinete4.obj");
    Model Perilla1((char*)"Models/Cocina/Perilla1/perilla1.obj");
    Model Perilla2((char*)"Models/Cocina/Perilla2/perilla2.obj");
    Model Perilla3((char*)"Models/Cocina/Perilla3/perilla3.obj");
    Model Perilla4((char*)"Models/Cocina/Perilla4/perilla4.obj");
    Model Pasto((char*)"Models/Cocina/pasto.obj");
    /*Model Puertita((char*)"Models/Cocina/Puertita/puertita.obj");
    Model Chapa((char*)"Models/Cocina/Chapa/chapa.obj");*/
    
    


    glm::mat4 projection = glm::perspective(camera.GetZoom(), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Set frame time
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Check and call events
        glfwPollEvents();
        DoMovement();

        // Clear the colorbuffer
        glClearColor(0.364, 0.796, 0.992, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.Use();

        glm::mat4 view = camera.GetViewMatrix();
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));

        // Draw the loaded model

        //REFRIGERADOR
        glm::mat4 model(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Refrigerador.Draw(shader);

         //Ventana 
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Ventana.Draw(shader);

        //Ventana Sala
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        VentanaSala.Draw(shader);

            //Paredes COCINA
        model = glm::mat4(1);
        //model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        ParedesCocina.Draw(shader);

        //Paredes Sala
        model = glm::mat4(1);
        //model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        ParedesSala.Draw(shader);

        //Chiminea
        model = glm::mat4(1);
        //model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Chimenea.Draw(shader);

        //MODELOS
        model = glm::mat4(1);
        //model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Lampara.Draw(shader);

        //Puerta cocina
        model = glm::mat4(1);
        //model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Puertita.Draw(shader);

        //Fachada
        model = glm::mat4(1);
        //model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Fachada.Draw(shader);

        //Puerta CASA
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        model = glm::rotate(model, glm::radians(rot5), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        PuertaCasa.Draw(shader);

        //Cajonera 
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Cajonera.Draw(shader);

        //Silla estática 
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Silla1.Draw(shader);

        //Mesa 
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Mesa.Draw(shader);

        //Fregadero 
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Fregadero.Draw(shader);

        //Gabinete 
        model = glm::mat4(1);
        //model = glm::translate(model, glm::vec3(-4.21, 1.7, 10.7));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Gabinete.Draw(shader);

        //Puerta Gabinete 1
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.18, 0.78, -6.79));
        model = glm::rotate(model, glm::radians(rot1), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Gabinete1.Draw(shader);

        //Puerta Gabinete 2
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.18, 0.79, -8.86));
        model = glm::rotate(model, glm::radians(rot2), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Gabinete2.Draw(shader);

        //Puerta Gabinete 3
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.18, 0.78, -8.986));
        model = glm::rotate(model, glm::radians(rot3), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Gabinete3.Draw(shader);

        //Puerta Gabinete 4
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.18, 0.795, -11.1));
        model = glm::rotate(model, glm::radians(rot4), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Gabinete4.Draw(shader);

        //Estufa
        model = glm::mat4(1);
       // model = glm::translate(model, glm::vec3(8.18, 0.795, -11.1));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Estufa.Draw(shader);

        //Perilla 1
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.115, 1.26, -2.6));
        model = glm::rotate(model, glm::radians(rot11), glm::vec3(1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Perilla1.Draw(shader);

        //Perilla 2
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.115, 1.26, -2.8));
        model = glm::rotate(model, glm::radians(rot12), glm::vec3( 1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Perilla2.Draw(shader);

        //Perilla 3
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.115, 1.26, -3.45));
        model = glm::rotate(model, glm::radians(rot13), glm::vec3(1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Perilla3.Draw(shader);

        //Perilla 4
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(8.115, 1.26, -3.65));
        model = glm::rotate(model, glm::radians(rot14), glm::vec3(1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Perilla4.Draw(shader);

        //Silla 2
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(1.6, 0.182, -7.86));
        model = glm::translate(model, glm::vec3(0.0, 0.0, mov));
        model = glm::rotate(model, glm::radians(rot9), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rot10), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Silla2.Draw(shader);

        //Bote
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Bote.Draw(shader);

        //Tapa de bote
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(5.187, 0.8, -11.2));
        model = glm::rotate(model, glm::radians(rot0), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::translate(model, glm::vec3(mov1, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rot15), glm::vec3(0.0f, 0.0f, 1.0f)); 
        model = glm::translate(model, glm::vec3(0.0f, mov2, 0.0f));
        model = glm::rotate(model, glm::radians(rot16), glm::vec3(0.0f, 0.0f, 1.0f));
        //model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        TapaBote.Draw(shader);

       

        //Puerta cocina
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(7.737, 1.705, -11.4));
        model = glm::rotate(model, glm::radians(rot7), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        PuertaCocina.Draw(shader);

        //Pasto
        model = glm::mat4(1);
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        Pasto.Draw(shader);

        // Swap the buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

// Moves/alters the camera positions based on user input
void DoMovement()
{
    // Camera controls
    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
    {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }

    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
    {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }

    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
    {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }

    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
    {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }

    //ANIMACION BOTE BASURA
    if (bote)
    {
        if (on)
        {
            off = false;
            if (rot0 > -90.0f)
                rot0 -= 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot0 < 0.0f)
                rot0 += 0.5f;
          /*  else
                on = true;*/
        }
    }
    //ANIMACION GABINETE PUERTAS DERECHAS
    if (gabinetesder)
    {
        if (on)
        {
            off = false;
            if (rot1 > 0.0f)
                rot1 -= 0.5f;
            if (rot2 < 0.0f)
                rot2 += 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot1 < 90.0f)
                rot1 += 0.5f;
            if (rot2 > -90.0f)
                rot2 -= 0.5f;
            else
                on = true;
        }
    }

    //ANIMACION GABINETE PUERTAS DERECHAS
    if (gabinetesizq)
    {
        if (on)
        {
            off = false;
            if (rot3 > 0.0f)
                rot3 -= 0.5f;
            if (rot4 < 0.0f)
                rot4 += 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot3 < 90.0f)
                rot3 += 0.5f;
            if (rot4 > -90.0f)
                rot4 -= 0.5f;
            else
                on = true;
        }
    }
    //ANIMACION PUERTA PRINCIPAL
   
    if (puertaF)
    {
        if (on)
        {
            off = false;
            if (rot5 < 90.0f)
                rot5 += 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot5 > 0.0f)
                rot5 -= 0.5f;
            /*  else
                  on = true;*/
        }
    }

    //ANIMACION PUERTA COCINA

    if (puertaC)
    {
        if (on)
        {
            off = false;
            if (rot7 > -90.0f)
                rot7 -= 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot7 < 0.0f)
                rot7 += 0.5f;
            /*  else
                  on = true;*/
        }
    }

  
    ////ANIMACION COMPLETA PUERTA
    //if (puertaC)
    //{
    //    if (chapa) {

    //        puerta = false;
    //        puertita = false;

    //        if (rot6 < 180.0f)
    //            rot6 += 0.3f; //Rotacion chapa
    //        else
    //            puerta = true; 
    //    }

    //    if (puerta) {

    //        puertita = false;

    //        if (rot7 > -90.0f)
    //            rot7 -= 0.5f;

    //        else
    //            puertita = true;
    //            //puertita = !puertita;

    //    }
    //    
    //    if (puertita)
    //    {
    //        //puertita = !puertita;
    //        if (on1)
    //        {
    //            off1 = false;
    //            if (rot8 < 45.0f)
    //                rot8 += 0.5f;

    //            else
    //                off1 = true;
    //        }
    //        if (off1)
    //        {
    //            on1 = false;
    //            if (rot8 > 0.0f)
    //                rot8 -= 0.5f;

    //            /*else
    //                on1 = true;*/
    //        }
    //    }
    //}

    //ANIMACION SILLA

    if (silla)
    {
        if (mover) {
            caer = false;
            girar = false;

            if (mov > -0.6f)
                mov -= 0.15f; //Se cae
            else
                caer = true;

        }

        if (caer) {

            girar = false;
            
            if (rot9 > -90.0f)
                rot9 -= 1.f; //Se cae
            else
                girar = true;
        }
       
        if (girar)
        {
            off2 = false;
            if (rot10 > -15.0f)
                rot10 -= 0.8f;
            else
                off = true;
        }
        if (off2)
        {
            on2 = false;
            if (rot10 < 0.0f)
                rot10 += 0.5f;
              else
                  on2 = true;
        }
    }


    //ANIMACION PERILLAS
    if (perilla1)
    {
        if (on)
        {
            off = false;
            if (rot11 < 90.0f)
                rot11 += 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot11 > -90.0f)
                rot11 -= 0.5f;
            /*  else
                  on = true;*/
        }
    }

    if (perilla2)
    {
        if (on)
        {
            off = false;
            if (rot12 < 90.0f)
                rot12 += 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot12 > -90.0f)
                rot12 -= 0.5f;
            /*  else
                  on = true;*/
        }
    }

    if (perilla3)
    {
        if (on)
        {
            off = false;
            if (rot13 < 90.0f)
                rot13 += 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot13 > -90.0f)
                rot13 -= 0.5f;
            /*  else
                  on = true;*/
        }
    }

    if (perilla4)
    {
        if (on)
        {
            off = false;
            if (rot14 < 90.0f)
                rot14 += 0.5f;
            else
                off = true;
        }
        if (off)
        {
            on = false;
            if (rot14 > -90.0f)
                rot14 -= 0.5f;
            /*  else
                  on = true;*/
        }
    }

    //ANIMACION BOTE COMPLEJA
    if (drop)
    {
        if (rodar1) {

            rodar2 = false;
            if (rot15 < 360.0f)
                rot15 += 10.0f;

            if (mov1 > -0.6f)
                mov1 -= 0.07f;

            
            //Se cae
            else
                rodar2 = true;

        }

        if (rodar2) {

            if (mov2 > -0.6f)
                mov2 -= 0.07f;
            //Se cae
           /* else
                rodar2 = true;*/

        }

    }

}

// Is called whenever a key is pressed/released via GLFW
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            keys[key] = false;
        }
    }

    if (keys[GLFW_KEY_1])
    {
        on = true;
        bote = !bote;

    }

    if (keys[GLFW_KEY_2])
    {
        on = true;
        gabinetesder = !gabinetesder;

    }

    if (keys[GLFW_KEY_3])
    {
        on = true;
        gabinetesizq = !gabinetesizq;

    }

    if (keys[GLFW_KEY_4])
    {
        on = true;
        puertaF = !puertaF;
 
    }

    if (keys[GLFW_KEY_5])
    {
        on = true;
        puertaC = !puertaC;

    }

    ///*if (keys[GLFW_KEY_5])
    //{
    //   
    //    puertaC = true;
    //    chapa = true;
    //    on1 = true;*/
    //    
    //}

    if (keys[GLFW_KEY_6])
    {
        silla = true;
        mover = true;
        on2 = true;

    }

    if (keys[GLFW_KEY_7])
    {
        on = true;
        perilla1 = !perilla1;

    }

    if (keys[GLFW_KEY_8])
    {
        on = true;
        perilla2 = !perilla2;

    }

    if (keys[GLFW_KEY_9])
    {
        on = true;
        perilla3 = !perilla3;

    }

    if (keys[GLFW_KEY_0])
    {
        on = true;
        perilla4 = !perilla4;

    }

    if (keys[GLFW_KEY_B])
    {
        drop = true;
        rodar1 = true;

    }

}

void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{
    if (firstMouse)
    {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }

    GLfloat xOffset = xPos - lastX;
    GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left

    lastX = xPos;
    lastY = yPos;

    camera.ProcessMouseMovement(xOffset, yOffset);
}






////Pedal de bote
       //model = glm::mat4(1);
       //model = glm::translate(model, glm::vec3(4.83, 0.3, -10.73));
       //model = glm::rotate(model, glm::radians(rot1), glm::vec3(0.0f, 0.0f, 1.0f));
       //glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
       //PedalBote.Draw(shader);

       ////Chapa
       //model = glm::mat4(1);
       //model = glm::translate(model, glm::vec3(6.06, 1.55, -11.4));
       //model = glm::rotate(model, glm::radians(rot6), glm::vec3(0.0f, 0.0f, 1.0f));
       //glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
       //Chapa.Draw(shader);
       // 
       ////Puertita
       //model = glm::mat4(1);
       //model = glm::translate(model, glm::vec3(6.78, 1.15, -11.39));
       //model = glm::rotate(model, glm::radians(rot8), glm::vec3(1.0f, 0.0f, 0.0f));
       //glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
       //Puertita.Draw(shader);