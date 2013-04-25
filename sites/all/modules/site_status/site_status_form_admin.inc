<?php

function site_status_admin_form($form, &$form_state) {
  $form['action'] = array(
      '#type' => 'textfield',
      '#title' => t('Action'),
      '#default_value' => variable_get('site_action', null),
      '#description' => t('Please enter the site-wide action. E.g. listening to music.'),
      '#required' => true,
      '#size' => 20,
      '#maxlength' => 255,
  );

  $form['submit'] = array(
      '#value' => t('Save'),
      '#type' => 'submit',
  );
  return $form;
}

//@todo Add any required validation.
function site_status_admin_form_validate($form, &$form_state){
  
}

function site_status_admin_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  variable_set('site_action', $values['action']);
}