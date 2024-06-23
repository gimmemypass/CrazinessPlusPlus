#include "EditorState.h"
#include "../Systems/SpriteRendererSystem.h"
#include "../SystemsHelper.h"
#include <memory>


void EditorState::OnEnter()
{
	AddSystems(); 
}

void EditorState::OnExit()
{

}

void EditorState::Update(float dt)
{
	UpdateSystems(dt);
}

size_t EditorState::NextState()
{
	return size_t();
}

void EditorState::AddSystems()
{
	SystemsHelper::AddDefaultSystems(systems, reg);
}