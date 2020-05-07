#pragma once

// For use by Hazel applications

#include "Hazel/Application.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Input.h"
#include "Hazel/KeyCodes.h"
#include "Hazel/Layer.h"
#include "Hazel/Log.h"
#include "Hazel/MouseButtonCodes.h"
#include "Hazel/AssertionHandler.h"
#include "Hazel/Timestep.h"
#include "Hazel/OrtographicCameraController.h"

// ---Events--------------------------
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"
// -----------------------------------

// ---Renderer------------------------
#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/GraphicsContext.h"
#include "Hazel/Renderer/OrtographicCamera.h"
#include "Hazel/Renderer/RenderCommand.h"
#include "Hazel/Renderer/Renderer.h"
#include "Hazel/Renderer/RendererAPI.h"
#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/Texture.h"
// -----------------------------------

// ---Entry Point---------------------
#include "Hazel/EntryPoint.h"
// -----------------------------------

// --- Temporary ---------------------
#include "Platform/OpenGL/OpenGLShader.h"
// -----------------------------------
