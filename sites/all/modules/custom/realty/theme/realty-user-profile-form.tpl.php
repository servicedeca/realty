<div class="tabbable">
  <ul class="nav nav-tabs">
    <li class="active"><a href="#pane1" data-toggle="tab"><?php print t('General'); ?></a></li>
    <li><a href="#pane2" data-toggle="tab"><?php print t('Change Password'); ?></a></li>
    <li><a href="#pane3" data-toggle="tab"><?php print t('Payment information')?></a></li>
  </ul>
  <div class="tab-content">
    <div id="pane1" class="tab-pane active">
      <div class="col-md-5">
        <?php print render($form['account']['mail']); ?>
        <?php print drupal_render($form['field_user_name']); ?>
        <?php print render($form['field_last_name']); ?>
        <?php print render($form['field_patronymic']); ?>
        <?php print render($form['field_phone_number']); ?>
      </div>
    </div>
    <div id="pane2" class="tab-pane">
      <?php print render($form['account']['current_pass']); ?>
      <?php print render($form['account']['pass']); ?>
      <?php print render($form['account']['current_pass_required_values']); ?>
    </div>
    <div id="pane3" class="tab-pane">
    </div>
    <div class="col-md-8">
      <?php print render($form['actions']['submit']); ?>
      <?php print render($form['actions']['cancel']); ?>
    </div>
  </div>
</div>
<div class="element-hidden">
  <?php print drupal_render_children($form); ?>
</div>