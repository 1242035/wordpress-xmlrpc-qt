/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "labels.h"

Labels::Labels(){
this->tablename = "labels";
this->size = 17;
this->Labels_db = new Database();	
}
Labels::~Labels(){
delete this->Labels_db;	
}
       
       //get
QString Labels::Labels_get_name(){return this->name ;}
QString Labels::Labels_get_menu_name(){return this->menu_name ;}
QString Labels::Labels_get_name_admin_bar(){return this->name_admin_bar ;}
QString Labels::Labels_get_singular_name(){return this->singular_name ;}
QString Labels::Labels_get_search_items(){return this->search_items ;}
QString Labels::Labels_get_popular_items(){return this->popular_items ;}
QString Labels::Labels_get_all_items(){return this->all_items ;}
QString Labels::Labels_get_parent_item(){return this->parent_item ;}
QString Labels::Labels_get_parent_item_colon(){return this->parent_item_colon ;}
QString Labels::Labels_get_edit_item(){return this->edit_item ;}
QString Labels::Labels_get_update_item(){return this->update_item ;}
QString Labels::Labels_get_add_new_item(){return this->add_new_item ;}
QString Labels::Labels_get_new_item_name(){return this->new_item_name ;}
QString Labels::Labels_get_separate_items_with_commas(){return this->separate_items_with_commas ;}
QString Labels::Labels_get_add_or_remove_items(){return this->add_or_remove_items ;}
QString Labels::Labels_get_choose_from_most_used(){return this->choose_from_most_used ;}
QString Labels::Labels_get_view_item(){return this->view_item ;}
//set
void Labels::Labels_set_name(QString name){this->name = name ;}
void Labels::Labels_set_menu_name(QString menu_name){this->menu_name = menu_name ;}
void Labels::Labels_set_name_admin_bar(QString name_admin_bar){this->name_admin_bar = name_admin_bar ;}
void Labels::Labels_set_singular_name(QString singular_name){this->singular_name = singular_name ;}
void Labels::Labels_set_search_items(QString search_items){this->search_items = search_items ;}
void Labels::Labels_set_popular_items(QString popular_items){this->popular_items = popular_items ;}
void Labels::Labels_set_all_items(QString all_items){this->all_items = all_items ;}
void Labels::Labels_set_parent_item(QString parent_item){this->parent_item = parent_item ;}
void Labels::Labels_set_parent_item_colon(QString parent_item_colon){this->parent_item_colon = parent_item_colon ;}
void Labels::Labels_set_edit_item(QString edit_item){this->edit_item = edit_item ;}
void Labels::Labels_set_update_item(QString update_item){this->update_item = update_item ;}
void Labels::Labels_set_add_new_item(QString add_new_item){this->add_new_item = add_new_item ;}
void Labels::Labels_set_new_item_name(QString new_item_name){this->new_item_name = new_item_name ;}
void Labels::Labels_set_separate_items_with_commas(QString separate_items_with_commas){
this->separate_items_with_commas = separate_items_with_commas ;	
}
void Labels::Labels_set_add_or_remove_items(QString add_or_remove_items){
this->add_or_remove_items = add_or_remove_items ;	
}
void Labels::Labels_set_choose_from_most_used(QString choose_from_most_used){
this->choose_from_most_used = choose_from_most_used ;	
}
void Labels::Labels_set_view_item(QString view_item){this->view_item = view_item ;}
//get size
int Labels::Labels_get_size(){return this->size ;}
//insert database
void Labels::Labels_insert_db(){
	QStringList what;
	this->Labels_db->Database_select(this->tablename);
	int id = this->Labels_db->Database_num_rows();
	what<<QString::number(id++)<<this->name<<this->singular_name<<this->search_items \
    <<this->popular_items<<this->all_items<<this->parent_item<<this->parent_item_colon \
    <<this->edit_item<<this->update_item<<this->add_new_item<<this->new_item_name \
    <<this->separate_items_with_commas<<this->add_or_remove_items<<this->choose_from_most_used \
    <<this->menu_name<<this->name_admin_bar<<this->view_item;
	this->Labels_db->Database_insert(this->tablename,what);
}
int Labels::Labels_get_id(){
	this->Labels_db->Database_select(this->tablename);
	return this->Labels_db->Database_num_rows();
}
