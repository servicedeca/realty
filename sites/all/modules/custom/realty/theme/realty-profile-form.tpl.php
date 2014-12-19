<div class="tabbable">
  <ul class="nav nav-tabs">
    <li class="active"><a href="#pane1" data-toggle="tab"><?php print t('General'); ?></a></li>
    <li><a href="#pane2" data-toggle="tab"><?php print t('Change Password'); ?></a></li>
    <li><a href="#pane4" data-toggle="tab"></a></li>
  </ul>
  <div class="tab-content">
    <div id="pane1" class="tab-pane active">
      <div class="col-md-5">
        <?php print render($profile_form['account']['mail']); ?>
        <?php print render($profile_form['field_last_name'])?>
        <?php print render($profile_form['field_user_name'])?>
        <?php print render($profile_form['field_phone_number'])?>
        <?php print render($profile_form['field_patronymic'])?>
      </div>
    </div>
    <div id="pane2" class="tab-pane">
      <?php print render($profile_form['account']['current_pass'])?>
      <?php print render($profile_form['account']['pass'])?>
    </div>
    <div id="pane4" class="tab-pane">

    </div>
    <div class="col-md-8">
      <?php hide($profile_form['field_last_name'])?>
      <?php hide($profile_form['field_user_name'])?>
      <?php hide($profile_form['field_phone_number'])?>
      <?php hide($profile_form['field_patronymic'])?>
      <?php print drupal_render($profile_form); ?>
    </div>
  </div>
</div>
<div class="element-hidden">
  <?php print drupal_render($profile_form); ?>
</div>