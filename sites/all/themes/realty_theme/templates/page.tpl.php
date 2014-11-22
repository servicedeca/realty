<div class="global-wrap">
  <header id="main-header">
    <div class="header-top">
      <div class="container">
        <div class="row">
          <div class="col-md-8">
            <?php print render($logo);?>
          </div>
          <div class="col-md-4">
            <?php print render($login_profile);?>
            <?php print render($logout_register);?>
          </div>
        </div>
      </div>
    </div>
  </header>
  <div class="top-area show-onload">
    <div class="container">
      <div class="row">
        <div class="col-md-12">
          <?php print render($title_prefix); ?>
          <?php print render($title_suffix); ?>
          <?php if ($tabs): ?>
            <div class="tabs">
              <?php print render($tabs); ?>
            </div>
          <?php endif; ?>
          <?php if (!empty($action_links)): ?>
            <ul class="action-links">
              <?php print render($action_links); ?>
            </ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>
        </div>
      </div>
    </div>
  </div>
</div>